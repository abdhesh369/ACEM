import pygame
import random
from config import (
    SCREEN_WIDTH, SCREEN_HEIGHT, SKY_TOP, SKY_BOTTOM,
    COIN_COL, WHITE
)
from platform import Platform
from effects import effects
from enemy import Slime, Spikes
from audio import sounds

class Coin(pygame.sprite.Sprite):
    """A small spinning coin the player can collect."""

    RADIUS  = 9
    COLORS  = [COIN_COL, (255, 230, 80), (255, 200, 30)]

    def __init__(self, x: int, y: int):
        super().__init__()
        self._tick  = 0
        self.rect   = pygame.Rect(x - self.RADIUS, y - self.RADIUS,
                                  self.RADIUS * 2, self.RADIUS * 2)
        self.image  = self._make_image(0)

    def _make_image(self, tick: int) -> pygame.Surface:
        """Draw a coin with a simple shimmer cycle."""
        surf = pygame.Surface((self.RADIUS * 2, self.RADIUS * 2), pygame.SRCALPHA)
        color = self.COLORS[tick % len(self.COLORS)]
        pygame.draw.circle(surf, color,         (self.RADIUS, self.RADIUS), self.RADIUS)
        pygame.draw.circle(surf, (200, 160, 0), (self.RADIUS, self.RADIUS), self.RADIUS, 2)
        pygame.draw.line(surf, WHITE, (self.RADIUS, 3), (self.RADIUS, self.RADIUS * 2 - 3), 2)
        return surf

    def update(self):
        self._tick += 1
        if self._tick % 10 == 0:
            self.image = self._make_image(self._tick // 10)

    def draw(self, surface: pygame.Surface, camera_offset: int):
        draw_rect = self.rect.move(-camera_offset, 0)
        if draw_rect.right > 0 and draw_rect.left < surface.get_width():
            surface.blit(self.image, draw_rect)

class Cloud:
    """A simple procedural cloud that scrolls slower than the world (parallax)."""

    def __init__(self, x: int, y: int, scale: float = 1.0):
        self.x      = float(x)
        self.y      = y
        self.scale  = scale
        self.surf   = self._draw(scale)

    @staticmethod
    def _draw(scale: float) -> pygame.Surface:
        w, h = int(90 * scale), int(40 * scale)
        surf = pygame.Surface((w, h), pygame.SRCALPHA)
        pygame.draw.ellipse(surf, (255, 255, 255, 210), (0,      h // 3, w // 2,  h * 2 // 3))
        pygame.draw.ellipse(surf, (255, 255, 255, 210), (w // 4, 0,      w // 2,  h))
        pygame.draw.ellipse(surf, (255, 255, 255, 210), (w // 2, h // 3, w // 2,  h * 2 // 3))
        return surf

    def update(self):
        pass

    def draw(self, surface: pygame.Surface, camera_x: float):
        surface.blit(self.surf, (int(self.x - camera_x * 0.3), self.y))

GENERATE_AHEAD  = SCREEN_WIDTH + 400

CLEANUP_BEHIND  = SCREEN_WIDTH + 200

CHUNK_TEMPLATES = [

    {"ground_w": 350, "gap": 90,  "platform": None,                  "coins": [(80, -40), (160, -40), (240, -40)]},

    {"ground_w": 300, "gap": 110, "platform": (80,  -110, 120, True),  "coins": [(100, -150), (140, -150), (180, -150)]},

    {"ground_w": 400, "gap": 100, "platform": (100, -130, 130, True),  "coins": [(120, -170), (170, -170)]},

    {"ground_w": 200, "gap": 140, "platform": None,                  "coins": [(60, -40), (120, -40)]},

    {"ground_w": 320, "gap": 110, "platform": (60,  -100, 110, False), "coins": [(70, -140), (110, -140), (150, -140)]},

    {"ground_w": 450, "gap": 100, "platform": (150, -120, 140, True),  "coins": [(50, -40), (160, -160), (220, -160), (350, -40)]},

    {"ground_w": 400, "gap": 120, "platform": (50, -80, 80, False),    "coins": [(80, -120), (160, -160), (240, -200)], "extra_plat": (180, -160, 80)},

    {"ground_w": 350, "gap": 130, "platform": (40, -100, 100, True),   "coins": [(70, -140), (250, -140)], "extra_plat": (220, -100, 100)},

    {"ground_w": 180, "gap": 150, "platform": (20, -180, 140, False),  "coins": [(40, -220), (120, -220)]},
]

GROUND_Y      = 460
GROUND_H      = 30
MIN_GAP       = 90
MAX_GAP       = 160
GAP_GROW_RATE = 10

class Level:
    """
    Infinite procedurally generated level.
    Chunks are created ahead of the player and removed behind them.
    """

    def __init__(self):
        self._rng = random.Random(None)

        self.platforms: list[Platform] = []
        self.coins:     list[Coin]     = []
        self.clouds:    list[Cloud]    = []
        self.enemies:   list           = []

        self.camera_x: float = 0.0

        self._next_chunk_x: int = 0
        self._chunk_count:  int = 0
        self.score_distance: int = 0

        self.biome_index = 0

        self._bg = self._make_gradient()

        for _ in range(10):
            self.clouds.append(Cloud(
                self._rng.randint(-200, SCREEN_WIDTH + 800),
                self._rng.randint(40, 180),
                self._rng.uniform(0.7, 1.4)
            ))

        self._spawn_opening()

        self._generate_ahead(0)

    def _update_biomes(self):
        """Change colors every 4000 pixels."""
        new_biome = int(self.camera_x) // 4000
        if new_biome != self.biome_index:
            self.biome_index = new_biome

            colors = [
                ((40, 100, 200), (34, 139, 34)),
                ((20, 20, 60),   (100, 30, 30)),
                ((100, 50, 150), (200, 200, 100)),
                ((200, 200, 230),(150, 150, 200))
            ]
            sky, ground = colors[new_biome % len(colors)]
            self._bg = self._make_gradient(sky, (sky[0]//2, sky[1]//2, sky[2]//2))

    def _spawn_opening(self):
        """Flat safe ground at the start so the player lands safely."""
        self.platforms.append(Platform(0, GROUND_Y, 500, GROUND_H))
        self._next_chunk_x = 500

    def _current_max_gap(self) -> int:
        """Gap size grows gradually as more chunks are generated."""
        extra = (self._chunk_count // GAP_GROW_RATE) * 10
        return min(MIN_GAP + extra, 200)

    def _generate_ahead(self, player_x: int):
        """Keep spawning chunks until we're GENERATE_AHEAD pixels past the player."""
        while self._next_chunk_x < player_x + GENERATE_AHEAD:
            self._spawn_chunk(self._next_chunk_x)

    def _spawn_chunk(self, x: int):
        """Spawn one ground chunk + optional elevated platform + coins."""
        tmpl = self._rng.choice(CHUNK_TEMPLATES)

        ground_w = tmpl["ground_w"] + self._rng.randint(-80, 80)
        ground_w = max(ground_w, 120)

        self.platforms.append(Platform(x, GROUND_Y, ground_w, GROUND_H))

        if tmpl["platform"]:
            rel_x, rel_y, pw, can_move = tmpl["platform"]

            v_jitter = self._rng.randint(-30, 30)
            moving = can_move and self._rng.random() < min(0.3 + self._chunk_count * 0.02, 0.7)
            spd    = self._rng.uniform(1.0, 2.5) if moving else 0
            dist   = self._rng.randint(60, 120)  if moving else 0
            self.platforms.append(Platform(
                x + rel_x, GROUND_Y + rel_y + v_jitter,
                pw, 20, moving, dist, spd
            ))

            if not moving and self._rng.random() < 0.4:
                self.enemies.append(Slime(x + rel_x + 10, GROUND_Y + rel_y + v_jitter))

        if "extra_plat" in tmpl:
            ex, ey, ew = tmpl["extra_plat"]
            self.platforms.append(Platform(x + ex, GROUND_Y + ey, ew, 20))
        elif self._rng.random() < 0.15:
            rx = self._rng.randint(20, ground_w - 60)
            ry = self._rng.randint(-180, -90)
            self.platforms.append(Platform(x + rx, GROUND_Y + ry, 60, 20))

        for (cx, cy) in tmpl["coins"]:
            if self._rng.random() < 0.75:
                self.coins.append(Coin(x + cx, GROUND_Y + cy))

        if self._rng.random() < 0.25:
            spike_x = x + self._rng.randint(50, ground_w - 50)
            self.enemies.append(Spikes(spike_x, GROUND_Y))

        base_gap = tmpl.get("gap", MIN_GAP)
        max_g = max(base_gap + 20, self._current_max_gap())
        gap = self._rng.randint(base_gap, max_g)
        self._next_chunk_x = x + ground_w + gap
        self._chunk_count  += 1


    @staticmethod
    def _make_gradient(top_col=SKY_TOP, bot_col=SKY_BOTTOM) -> pygame.Surface:
        surf = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT))
        for y in range(SCREEN_HEIGHT):
            t = y / SCREEN_HEIGHT
            r = int(top_col[0] + (bot_col[0] - top_col[0]) * t)
            g = int(top_col[1] + (bot_col[1] - top_col[1]) * t)
            b = int(top_col[2] + (bot_col[2] - top_col[2]) * t)
            pygame.draw.line(surf, (r, g, b), (0, y), (SCREEN_WIDTH, y))
        return surf

    def update(self, player):
        """Update scroll, generation, and cleanup."""
        self._update_biomes()

        target_x     = player.rect.centerx - SCREEN_WIDTH // 3
        target_x     = max(0, target_x)
        camera_delta  = target_x - self.camera_x
        self.camera_x += camera_delta * 0.12

        self._generate_ahead(int(player.rect.x))
        cutoff = self.camera_x - CLEANUP_BEHIND
        self.platforms = [p for p in self.platforms if p.rect.right > cutoff]
        self.coins     = [c for c in self.coins     if c.rect.right > cutoff]
        self.enemies   = [e for e in self.enemies   if e.rect.right > cutoff]

        for plat in self.platforms:
            plat.update()

        for coin in self.coins:
            coin.update()

        collected = [c for c in self.coins if player.rect.colliderect(c.rect)]
        for coin in collected:
            self.coins.remove(coin)
            player.score += 10
            effects.emit_sparkle(coin.rect.centerx, coin.rect.centery)
            sounds.play_coin()

        self.score_distance = player.rect.x // 10

        for cloud in self.clouds:
            screen_x = cloud.x - self.camera_x * 0.3
            if screen_x + 200 < 0:
                cloud.x = self.camera_x * 0.3 + SCREEN_WIDTH + 100
                cloud.y = self._rng.randint(40, 180)

        for enemy in self.enemies:
            enemy.update(self.platforms)

        if player.rect.top > SCREEN_HEIGHT + 60:
            if not player.invincible:
                player.lives -= 1
                sounds.play_death()
            player.respawn(max(80, int(self.camera_x) + 100), 380)

    def draw(self, surface: pygame.Surface):
        surface.blit(self._bg, (0, 0))

        for cloud in self.clouds:
            cloud.draw(surface, self.camera_x)

        cam = int(self.camera_x)
        for plat in self.platforms:
            plat.draw(surface, cam)

        for enemy in self.enemies:
            enemy.draw(surface, cam)

        for coin in self.coins:
            coin.draw(surface, cam)
