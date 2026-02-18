import pygame
from config import GRASS_COL, GROUND_COL, PLAT_COL

class Platform(pygame.sprite.Sprite):
    """
    A rectangular platform the player can stand on.

    Parameters
    ----------
    x, y          : Top-left world position (pixels)
    width, height : Size of the platform
    moving        : If True the platform oscillates horizontally
    move_dist     : Pixels to travel in each direction (for moving platforms)
    move_speed    : Pixels per frame of horizontal travel
    """

    def __init__(
        self,
        x: int,
        y: int,
        width: int,
        height: int,
        moving: bool = False,
        move_dist: int = 80,
        move_speed: float = 1.5,
    ):
        super().__init__()

        self.moving     = moving
        self.move_dist  = move_dist
        self.move_speed = move_speed

        self._origin_x  = x
        self._direction = 1
        self._prev_x    = x

        self.image = self._build_surface(width, height, moving=moving)
        self.rect  = self.image.get_rect(topleft=(x, y))

        self._x_precise: float = float(x)

    @staticmethod
    def _build_surface(width: int, height: int, moving: bool = False) -> pygame.Surface:
        """
        Draw a platform tile.  Moving platforms get a distinct tan/brown color;
        static platforms get green grass on brown earth.
        """
        surf = pygame.Surface((width, height))

        if moving:

            surf.fill(PLAT_COL)
            top_color = (160, 120, 70)
            highlight = (180, 140, 90)
            shadow    = (80,  50,  20)
        else:

            surf.fill(GROUND_COL)
            top_color = GRASS_COL
            highlight = (120, 210, 100)
            shadow    = (50,  30,  10)

        grass_h = min(8, height)
        pygame.draw.rect(surf, top_color, (0, 0, width, grass_h))

        pygame.draw.line(surf, highlight, (0, 0), (width - 1, 0))

        pygame.draw.line(surf, shadow, (0, height - 1), (width - 1, height - 1))

        return surf

    def update(self):
        """
        Oscillate the platform between origin_x and origin_x + move_dist.
        Static platforms skip this method's logic entirely.
        """
        if not self.moving:
            return

        self._prev_x         = self.rect.x
        self._x_precise     += self.move_speed * self._direction
        self.rect.x          = int(self._x_precise)

        if self._x_precise >= self._origin_x + self.move_dist:
            self._direction = -1
        elif self._x_precise <= self._origin_x:
            self._direction = 1

    def draw(self, surface: pygame.Surface, camera_offset: int):
        """Render the platform offset by the horizontal camera scroll."""
        draw_rect = self.rect.move(-camera_offset, 0)

        if draw_rect.right > 0 and draw_rect.left < surface.get_width():
            surface.blit(self.image, draw_rect)
