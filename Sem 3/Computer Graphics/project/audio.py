import pygame
import array
import math
import random

class SoundManager:
    """Generates and plays retro synth sounds using built-in array module."""
    def __init__(self):

        if not pygame.mixer.get_init():
            try:
                pygame.mixer.init(44100, -16, 2, 512)
            except:
                pass
        self.sample_rate = 44100
        self.sounds = {}

    def _generate_square(self, freq, duration, volume=0.1):
        """Square wave with linear decay using array.array."""
        n_samples = int(self.sample_rate * duration)
        samples = array.array('h', [0] * (n_samples * 2))

        for i in range(n_samples):

            val = 1 if math.sin(2 * math.pi * freq * (i / self.sample_rate)) > 0 else -1

            envelope = 1.0 - (i / n_samples)

            sample_val = int(val * envelope * volume * 32767)

            samples[i * 2] = sample_val
            samples[i * 2 + 1] = sample_val

        return pygame.mixer.Sound(buffer=samples)

    def _generate_noise(self, duration, volume=0.2):
        """White noise decay using array.array."""
        n_samples = int(self.sample_rate * duration)
        samples = array.array('h', [0] * (n_samples * 2))

        for i in range(n_samples):
            val = random.uniform(-1, 1)
            envelope = 1.0 - (i / n_samples)
            sample_val = int(val * envelope * volume * 32767)
            samples[i * 2] = sample_val
            samples[i * 2 + 1] = sample_val

        return pygame.mixer.Sound(buffer=samples)

    def play_jump(self):
        try:
            if "jump" not in self.sounds:
                self.sounds["jump"] = self._generate_square(440, 0.1, 0.08)
            self.sounds["jump"].play()
        except: pass

    def play_coin(self):
        try:
            if "coin" not in self.sounds:
                self.sounds["coin"] = self._generate_square(880, 0.15, 0.08)
            self.sounds["coin"].play()
        except: pass

    def play_death(self):
        try:
            if "death" not in self.sounds:
                self.sounds["death"] = self._generate_noise(0.5, 0.15)
            self.sounds["death"].play()
        except: pass

sounds = SoundManager()
