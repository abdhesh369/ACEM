import pygame
import random
from config import WHITE

class Particle:
    def __init__(self, x, y, vx, vy, life, color, size=3, gravity=0.1):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.life = life
        self.max_life = life
        self.color = color
        self.size = size
        self.gravity = gravity

    def update(self):
        self.vx *= 0.95
        self.vy += self.gravity
        self.x += self.vx
        self.y += self.vy
        self.life -= 1

    def draw(self, surface, camera_x):
        if self.life <= 0: return
        alpha = int(255 * (self.life / self.max_life))
        s = pygame.Surface((self.size * 2, self.size * 2), pygame.SRCALPHA)
        pygame.draw.circle(s, (*self.color, alpha), (self.size, self.size), self.size)
        surface.blit(s, (int(self.x - camera_x - self.size), int(self.y - self.size)))

class EffectManager:
    def __init__(self):
        self.particles = []
        self._shake_amount = 0
        self._shake_timer = 0

    def shake(self, amount=10, duration=15):
        """Trigger a screen shake."""
        self._shake_amount = amount
        self._shake_timer = duration

    def get_shake_offset(self):
        """Return (dx, dy) for current screen shake."""
        if self._shake_timer > 0:
            dx = random.uniform(-self._shake_amount, self._shake_amount)
            dy = random.uniform(-self._shake_amount, self._shake_amount)
            return dx, dy
        return 0, 0

    def emit_dust(self, x, y, count=8):
        """Puff of dust for landing or jumping."""
        for _ in range(count):
            vx = random.uniform(-1.5, 1.5)
            vy = random.uniform(-2, 0)
            life = random.randint(15, 30)
            self.particles.append(Particle(x, y, vx, vy, life, (200, 200, 200), size=random.randint(2, 4)))

    def emit_sparkle(self, x, y, color=(255, 255, 100)):
        """Sparkle effect for coin collection."""
        for _ in range(12):
            vx = random.uniform(-3, 3)
            vy = random.uniform(-3, 3)
            life = random.randint(20, 40)
            self.particles.append(Particle(x, y, vx, vy, life, color, size=2, gravity=0.05))

    def update(self):
        if self._shake_timer > 0:
            self._shake_timer -= 1
            self._shake_amount *= 0.9

        for p in self.particles:
            p.update()
        self.particles = [p for p in self.particles if p.life > 0]

    def draw(self, surface, camera_x):
        for p in self.particles:
            p.draw(surface, camera_x)

effects = EffectManager()
