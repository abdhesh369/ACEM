# 🕹️ Premium 2D Platformer 🎮

Welcome to the **Premium 2D Platformer**! This is an endless, procedurally generated adventure built entirely in **Python + Pygame**. 

The best part? **Zero external files are required.** Every cloud, character, and sound effect is generated in real-time by math and code!

---

## 👋 What is this game?
Imagine an endless world that builds itself as you run. You play as a small hero navigating through floating platforms, collecting coins, and dodging dangerous slimes. As you travel further, the world changes colors (Biomes) and the challenges get tougher!

### ✨ Key Highlights
- **💨 Motion Trails & Juice**: Feel the speed with visual trails and smooth animations.
- **🌍 Dynamic Biomes**: Watch the world shift from a sunny day to a dark "Hell" realm, or even an alien planet every 4000 pixels.
- **👾 Smart Hazards**: Watch out for patrolling Slimes and sharp Spikes.
- **🔊 Synth Audio**: Retro sound effects generated on-the-fly without any .MP3 files.
- **🏆 High Scores**: Your personal best is saved automatically to `highscore.txt`.

---

## 🎮 How to Play

### 1. Requirements
You only need **Python** installed. To install the game core:
```bash
pip install pygame
```

### 2. Launching
Navigate to the folder and run:
```bash
python main.py
```

### 3. Controls
| Action | Keyboard |
| :--- | :--- |
| **Move Left / Right** | `A` & `D`  or  `←` & `→` |
| **Jump** | `Space`, `W`, or `↑` |
| **Restart Game** | `R` (after you lose your 3 lives) |
| **Quit** | `Esc` |

---

## 🛠️ Technical Breakdown (For Developers)

The game is built with a modular architecture to keep the code clean and easy to hack:

- **`main.py`**: The "Brain". Handles the game loop, HUD, and high score saving.
- **`player.py`**: The "Hero". Manages 2D physics, jump arcs, and visual "juice" (particles/trails).
- **`level.py`**: The "World". Uses a chunk-based procedural generator to build the level endlessly.
- **`enemy.py`**: The "Bad Guys". Custom AI for slimes and procedural drawing for spikes.
- **`audio.py`**: The "Synth". A real-time wave generator that creates sound using `array` and `pygame.mixer`.
- **`effects.py`**: The "Atmosphere". Manages the particle system (dust/sparkles) and screen shake.
- **`config.py`**: The "Settings". Change gravity, speed, or screen size here.

### 🧪 Advanced Tweaking
Want to make the game harder? Open **`level.py`** and tweak:
- `MIN_GAP` & `MAX_GAP`: Widens the distance between platforms.
- `GAP_GROW_RATE`: Controls how quickly the game gets difficult.

---

## 🚀 No-Asset Philosophy
This project uses **procedural generation** for everything:
1. **Graphics**: Everything is drawn using `pygame.draw` (polygons, ellipses, circles).
2. **Audio**: Sounds are synthesized as raw wave data in `audio.py`.
3. **Levels**: No two runs are ever the same!

Enjoy the run! Can you reach the Alien Biome? 🛸💨
