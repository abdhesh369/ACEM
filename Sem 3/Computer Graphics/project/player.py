import pygame
from config import (
    PLAYER_W, PLAYER_H, MOVE_SPEED, JUMP_FORCE,
    GRAVITY, MAX_FALL_SPEED, ANIM_SPEED,
    BLACK
)
from effects import effects
from audio import sounds

def _draw_player_frame(color_body, color_face, leg_offset: int) -> pygame.Surface:
    """Return one 32×48 frame drawn with simple shapes."""
    surf = pygame.Surface((PLAYER_W, PLAYER_H), pygame.SRCALPHA)

    pygame.draw.rect(surf, color_body, (8, 14, 16, 20), border_radius=4)

    pygame.draw.ellipse(surf, color_face, (6, 2, 20, 20))

    pygame.draw.circle(surf, BLACK, (12, 10), 2)
    pygame.draw.circle(surf, BLACK, (20, 10), 2)

    pygame.draw.rect(surf, color_body, (8,  34 + leg_offset, 6, 10), border_radius=2)

    pygame.draw.rect(surf, color_body, (18, 34 - leg_offset, 6, 10), border_radius=2)

    pygame.draw.rect(surf, color_body, (2,  16, 6, 12), border_radius=2)
    pygame.draw.rect(surf, color_body, (24, 16, 6, 12), border_radius=2)
    return surf

def build_frames() -> dict:
    """
    Build all animation frames and return them in a dictionary.
      'idle'  : 2 frames (subtle breathing)
      'walk'  : 4 frames (leg swing)
      'jump'  : 1 frame  (knees bent up)
    """
    BODY  = (70,  130, 180)
    FACE  = (255, 220, 177)
    frames = {}

    frames["idle"] = [
        _draw_player_frame(BODY, FACE, 0),
        _draw_player_frame(BODY, FACE, 1),
    ]

    frames["walk"] = [
        _draw_player_frame(BODY, FACE,  4),
        _draw_player_frame(BODY, FACE,  2),
        _draw_player_frame(BODY, FACE, -4),
        _draw_player_frame(BODY, FACE, -2),
    ]

    jump_surf = pygame.Surface((PLAYER_W, PLAYER_H), pygame.SRCALPHA)
    pygame.draw.rect(jump_surf, BODY, (8, 16, 16, 18), border_radius=4)
    pygame.draw.ellipse(jump_surf, FACE, (6, 2, 20, 20))
    pygame.draw.circle(jump_surf, BLACK, (12, 10), 2)
    pygame.draw.circle(jump_surf, BLACK, (20, 10), 2)
    pygame.draw.rect(jump_surf, BODY,  (8,  34, 6, 8), border_radius=2)
    pygame.draw.rect(jump_surf, BODY,  (18, 34, 6, 8), border_radius=2)

    pygame.draw.rect(jump_surf, BODY, (0,  10, 8, 10), border_radius=2)
    pygame.draw.rect(jump_surf, BODY, (24, 10, 8, 10), border_radius=2)
    frames["jump"] = [jump_surf]

    return frames

class Player(pygame.sprite.Sprite):
    """
    The main player character.

    Attributes
    ----------
    rect       : pygame.Rect  — axis-aligned bounding box (world coords)
    vel_x/y    : float        — current velocity
    on_ground  : bool         — True while standing on a platform
    facing     : int          — +1 right, -1 left (for sprite flip)
    score      : int          — coins collected
    lives      : int
    """

    def __init__(self, x: int, y: int):
        super().__init__()

        self._frames    = build_frames()
        self._invincible_timer = 0
        self._state     = "idle"
        self._frame_idx = 0
        self._anim_tick = 0

        self.facing = 1

        self.image = self._frames["idle"][0]
        self.rect  = self.image.get_rect(topleft=(x, y))

        self.vel_x: float = 0.0
        self.vel_y: float = 0.0
        self._pos_x: float = float(x)
        self._pos_y: float = float(y)
        self.on_ground: bool = False
        self._riding_platform = None
        self.score = 0

        self.lives = 3

        self._prev_on_ground = False
        self._trail_points = []

    @property
    def invincible(self) -> bool:
        """True while the player has post-respawn invincibility."""
        return self._invincible_timer > 0

    def respawn(self, x: int, y: int):
        """Move player to spawn point and reset velocity."""
        self._pos_x = float(x)
        self._pos_y = float(y)
        self.rect.topleft = (int(self._pos_x), int(self._pos_y))
        self.vel_x = 0.0
        self.vel_y = 0.0
        self.on_ground = False
        self._riding_platform = None
        self._invincible_timer = 120

    def update(self, platforms, enemies, keys):
        """
        Called once per frame.
          1. Read keyboard input → set horizontal velocity & jump.
          2. Apply gravity.
          3. Move horizontally, resolve collisions.
          4. Move vertically, resolve collisions.
          5. Check enemy collisions.
          6. Advance animation & juice.
        """
        self._handle_input(keys)
        self._apply_gravity()
        self._move_and_collide(platforms)
        self._check_hazards(enemies)
        self._update_animation()
        self._update_juice()
        if self._invincible_timer > 0:
            self._invincible_timer -= 1

    def _check_hazards(self, enemies):
        """Check for collision with enemies or spikes."""
        if self.invincible: return

        for en in enemies:
            if self.rect.colliderect(en.rect):
                self.lives -= 1
                self._invincible_timer = 120
                effects.shake(10, 20)
                sounds.play_death()
                break

    def _handle_input(self, keys):
        """Translate key state into velocity changes."""
        self.vel_x = 0.0

        if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            self.vel_x = MOVE_SPEED
            self.facing = 1

        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            self.vel_x = -MOVE_SPEED
            self.facing = -1

        if (keys[pygame.K_SPACE] or keys[pygame.K_UP] or keys[pygame.K_w]) and self.on_ground:
            self.vel_y   = JUMP_FORCE
            self.on_ground = False
            effects.emit_dust(self.rect.centerx, self.rect.bottom)
            sounds.play_jump()

    def _apply_gravity(self):
        """Pull the player downward each frame."""
        self.vel_y += GRAVITY
        if self.vel_y > MAX_FALL_SPEED:
            self.vel_y = MAX_FALL_SPEED

    def _move_and_collide(self, platforms):
        """
        Split movement into two passes (horizontal then vertical) so we can
        resolve each axis independently — the classic platformer trick that
        prevents corner-catching bugs.

        Moving-platform riding: before applying physics we carry the player
        along with whatever platform they were standing on last frame.
        """

        if self.on_ground and self._riding_platform is not None:
            plat = self._riding_platform
            if plat.moving:
                self._pos_x += plat.rect.x - plat._prev_x

        self._pos_x += self.vel_x
        self.rect.x  = int(self._pos_x)

        if self.rect.left < 0:
            self.rect.left = 0

        for plat in platforms:
            if self.rect.colliderect(plat.rect):

                if self.vel_x > 0:
                    self.rect.right = plat.rect.left
                    self._pos_x = float(self.rect.x)
                elif self.vel_x < 0:
                    self.rect.left = plat.rect.right
                    self._pos_x = float(self.rect.x)

        self.on_ground          = False
        self._riding_platform   = None
        self._pos_y += self.vel_y
        self.rect.y  = int(self._pos_y)
        for plat in platforms:
            if self.rect.colliderect(plat.rect):
                if self.vel_y < 0:
                    self.rect.top = plat.rect.bottom
                    self._pos_y = float(self.rect.y)
                    self.vel_y = 0
                elif self.vel_y >= 0: # Changed from `if self.vel_y >= 0:` to `elif`
                    self.rect.bottom = plat.rect.top
                    self._pos_y = float(self.rect.y)
                    self.vel_y = 0
                    self.on_ground = True
                    self._riding_platform = plat
                    break # Moved break here

        if not self.on_ground:
            self.rect.y += 1
            for plat in platforms:
                if self.rect.colliderect(plat.rect):
                    self.on_ground = True
                    self._riding_platform = plat
                    break
            self.rect.y -= 1

    def _update_juice(self):
        """Update trails and detect landing for dust puffs."""

        if self.on_ground and not self._prev_on_ground:
            effects.emit_dust(self.rect.centerx, self.rect.bottom, count=12)
        self._prev_on_ground = self.on_ground

        if abs(self.vel_x) > 2 or not self.on_ground:
            self._trail_points.insert(0, (self.rect.x, self.rect.y, self.image.copy()))
        else:
            if self._trail_points: self._trail_points.pop()

        if len(self._trail_points) > 5:
            self._trail_points.pop()

    def _update_animation(self):
        """Choose the correct state, advance frames, and flip if needed."""

        if not self.on_ground:
            new_state = "jump"
        elif self.vel_x != 0:
            new_state = "walk"
        else:
            new_state = "idle"

        if new_state != self._state:
            self._state     = new_state
            self._frame_idx = 0
            self._anim_tick = 0

        self._anim_tick += 1
        if self._anim_tick >= ANIM_SPEED:
            self._anim_tick  = 0
            frame_list       = self._frames[self._state]
            self._frame_idx  = (self._frame_idx + 1) % len(frame_list)

        raw   = self._frames[self._state][self._frame_idx]
        self.image = pygame.transform.flip(raw, self.facing == -1, False)

    def draw(self, surface: pygame.Surface, camera_offset: int):
        """Draw the player offset by the camera scroll."""

        for i, (tx, ty, timg) in enumerate(self._trail_points):
            alpha = int(100 * (1 - i / len(self._trail_points)))
            temp  = timg.copy()
            temp.set_alpha(alpha)
            surface.blit(temp, (tx - camera_offset, ty))

        if self._invincible_timer > 0 and (self._invincible_timer // 6) % 2 == 0:
            return
        draw_rect = self.rect.move(-camera_offset, 0)
        surface.blit(self.image, draw_rect)
