import sys
import pygame

from config import (
    SCREEN_WIDTH, SCREEN_HEIGHT, FPS, TITLE,
    WHITE, BLACK, HUD_FONT_SIZE, COIN_COL
)
from player   import Player
from level    import Level
from effects  import effects
import os

SCORE_FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "highscore.txt")

def load_high_score():
    if os.path.exists(SCORE_FILE):
        try:
            with open(SCORE_FILE, "r") as f:
                return int(f.read().strip())
        except: return 0
    return 0

def save_high_score(score):
    try:
        with open(SCORE_FILE, "w") as f:
            f.write(str(score))
    except: pass

class HUD:
    """
    Heads-Up Display drawn over the game scene each frame.
    Shows: coin-score on the left, lives (♥) on the right.
    """

    HEART_COLOR  = (220, 50,  50)
    SCORE_COLOR  = COIN_COL
    TEXT_SHADOW  = (30,  30,  30)
    PANEL_COLOR  = (0,   0,   0,  140)

    def __init__(self):
        pygame.font.init()
        self._font       = pygame.font.SysFont("segoeui", HUD_FONT_SIZE, bold=True)
        self._font_small = pygame.font.SysFont("segoeui", HUD_FONT_SIZE - 4)

        self._panel      = pygame.Surface((SCREEN_WIDTH, 60), pygame.SRCALPHA)
        self._panel.fill(self.PANEL_COLOR)

    def draw(self, surface: pygame.Surface, player, level, frame_count: int, high_score: int):
        """Render score, lives, and a subtle top bar every frame."""

        surface.blit(self._panel, (0, 0))

        total = player.score + level.score_distance
        score_text = f"⬤  {total}"
        self._draw_text(surface, score_text, 16, 8, self.SCORE_COLOR)

        best = max(total, high_score)
        self._draw_text(surface, f"BEST: {best}", 16, 35, (150, 150, 150), small=True)

        hearts = "♥ " * player.lives + "♡ " * max(0, 3 - player.lives)
        self._draw_text(surface, f"Lives:  {hearts.strip()}", SCREEN_WIDTH - 180, 8, self.HEART_COLOR)

        HINT_SHOW  = 300
        HINT_FADE  = 60
        if frame_count < HINT_SHOW + HINT_FADE:
            alpha = 255
            if frame_count >= HINT_SHOW:
                alpha = int(255 * (1.0 - (frame_count - HINT_SHOW) / HINT_FADE))
            hint = "WASD / ↑←↓→ to move  •  SPACE to jump"
            hint_color = (200, 200, 200)
            rendered = self._font_small.render(hint, True, hint_color)
            shadow   = self._font_small.render(hint, True, self.TEXT_SHADOW)
            tmp = pygame.Surface(rendered.get_size(), pygame.SRCALPHA)
            tmp.blit(shadow, (1, 1))
            tmp.blit(rendered, (0, 0))
            tmp.set_alpha(alpha)
            surface.blit(tmp, (SCREEN_WIDTH // 2 - 195, SCREEN_HEIGHT - 26))

    def _draw_text(self, surface, text, x, y, color, small=False):
        font  = self._font_small if small else self._font

        shadow = font.render(text, True, self.TEXT_SHADOW)
        surface.blit(shadow, (x + 1, y + 1))

        rendered = font.render(text, True, color)
        surface.blit(rendered, (x, y))

def draw_overlay(surface: pygame.Surface, font, small_font, message: str, sub: str):
    """Draw a centred semi-transparent overlay with a message."""
    overlay = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
    overlay.fill((0, 0, 0, 160))
    surface.blit(overlay, (0, 0))

    text = font.render(message, True, WHITE)
    surface.blit(text, text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 - 30)))

    sub_text = small_font.render(sub, True, (200, 200, 200))
    surface.blit(sub_text, sub_text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 + 20)))

def main():
    pygame.init()
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption(TITLE)
    clock  = pygame.time.Clock()

    level  = Level()
    player = Player(80, 380)
    hud    = HUD()
    high_score = load_high_score()

    big_font   = pygame.font.SysFont("segoeui", 52, bold=True)
    small_font = pygame.font.SysFont("segoeui", 22)

    game_state   = "playing"
    frame_count  = 0

    while True:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit()

                if game_state == "dead" and event.key in (pygame.K_r, pygame.K_RETURN):
                    level       = Level()
                    player      = Player(80, 380)
                    game_state  = "playing"
                    frame_count = 0

        keys = pygame.key.get_pressed()

        if game_state == "playing":
            frame_count += 1
            player.update(level.platforms, level.enemies, keys)
            level.update(player)
            effects.update()

            if player.lives <= 0:
                game_state  = "dead"
                frame_count = 0
                effects.shake(15, 30)
                high_score = max(high_score, player.score + level.score_distance)
                save_high_score(high_score)

        shake_dx, shake_dy = effects.get_shake_offset()

        level.draw(screen)
        player.draw(screen, int(level.camera_x))
        effects.draw(screen, int(level.camera_x))
        hud.draw(screen, player, level, frame_count, high_score)

        if shake_dx != 0 or shake_dy != 0:
            screen_copy = screen.copy()
            screen.fill(BLACK)
            screen.blit(screen_copy, (shake_dx, shake_dy))

        if game_state == "dead":
            total_score = player.score + level.score_distance
            draw_overlay(screen, big_font, small_font, "GAME OVER",
                         f"Score: {total_score} (Best: {high_score})  •  Press R to restart")

        pygame.display.flip()
        clock.tick(FPS)

if __name__ == "__main__":
    main()