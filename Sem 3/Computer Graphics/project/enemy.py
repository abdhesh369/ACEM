import pygame
import math
import random
from config import BLACK

class Enemy(pygame.sprite.Sprite):
    def __init__(self, x, y, width, height):
        super().__init__()
        self.rect = pygame.Rect(x, y, width, height)

    def draw(self, surface, camera_x):
        draw_rect = self.rect.move(-camera_x, 0)
        if draw_rect.right > 0 and draw_rect.left < surface.get_width():
            surface.blit(self.image, draw_rect)

class Slime(Enemy):
    """A green patrolling enemy that moves back and forth."""
    def __init__(self, x, y):
        super().__init__(x, y - 24, 32, 24)
        self.vel_x = 1.5
        self.color = (50, 200, 50)
        self._anim_tick = 0
        self.image = self._draw_slime(0)

    def _draw_slime(self, tick):
        surf = pygame.Surface((32, 24), pygame.SRCALPHA)
        stretch = math.sin(tick * 0.2) * 4
        poly = [
            (2, 24), (30, 24),
            (28, 10 - stretch), (16, 2 - stretch), (4, 10 - stretch)
        ]
        pygame.draw.polygon(surf, self.color, poly)
        pygame.draw.circle(surf, BLACK, (12, 12 - stretch), 2)
        pygame.draw.circle(surf, BLACK, (20, 12 - stretch), 2)
        return surf

    def update(self, platforms):
        self._anim_tick += 1
        self.image = self._draw_slime(self._anim_tick)
        self.rect.x += self.vel_x
        turn = False
        side_rect = self.rect.copy()
        side_rect.x += self.vel_x * 2
        for plat in platforms:
            if side_rect.colliderect(plat.rect):
                turn = True
                break
        if not turn:
            foot_x = self.rect.right if self.vel_x > 0 else self.rect.left
            ledge_rect = pygame.Rect(foot_x, self.rect.bottom + 2, 2, 2)
            on_ledge = False
            for plat in platforms:
                if ledge_rect.colliderect(plat.rect):
                    on_ledge = True
                    break
            if not on_ledge:
                turn = True
        if turn:
            self.vel_x *= -1

class Spikes(Enemy):
    """Static hazard that points upward."""
    def __init__(self, x, y):
        super().__init__(x, y - 16, 32, 16)
        self.image = self._draw_spikes()

    def _draw_spikes(self):
        surf = pygame.Surface((32, 16), pygame.SRCALPHA)
        color = (150, 150, 160)
        for i in range(3):
            px = i * 10 + 6
            points = [(px - 6, 16), (px, 0), (px + 6, 16)]
            pygame.draw.polygon(surf, color, points)
            pygame.draw.polygon(surf, BLACK, points, 1)
        return surf

    def update(self, platforms):
        pass
