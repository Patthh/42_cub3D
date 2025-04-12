# 42 cub3D
<div id="desktop-banner">
<pre>
░█████╗░██╗░░░██╗██████╗░██████╗░██████╗░
██╔══██╗██║░░░██║██╔══██╗╚════██╗██╔══██╗
██║░░╚═╝██║░░░██║██████╦╝░█████╔╝██║░░██║
██║░░██╗██║░░░██║██╔══██╗░╚═══██╗██║░░██║
╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝
░╚════╝░░╚═════╝░╚═════╝░╚═════╝░╚═════╝░
</pre>
</div>
## 📖 What is `cub3D` 🎮?
<details>
<summary><b>A Wolfenstein 3D-inspired raycasting engine</b></summary><br>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cub3D is a project associated with the curriculum of École 42, a coding school known for its project-based learning approach.
The cub3D project uses the C programming language to create a simplified version of the raycasting engine used in games like Wolfenstein 3D.
The goal of this project is to teach students about graphics programming, mathematical concepts in 3D rendering, and optimization techniques while also assisting them in understanding how early 3D games were developed.
</p>
</details>

## ✅ Status
<details>
<summary><b>Project completion status</b></summary><br>
<p align="center">
Completed on : 2025-04-12 <br><br>
<img src="https://i.ibb.co/your-image-link/image.png" alt="Project Status">
</p>
</details>

## 🚀 Usage
To clone and compile:
```shell
git clone https://github.com/Patthh/42_cub3D.git
cd 42_cub3D && make
```
To run the game:
```shell
./cub3D maps/map.cub
```

## ✨ Features
- 🎮 First-person 3D-like view using raycasting technology
- 🖼️ Textured walls with different textures for North, South, East, and West facing walls
- 🏃‍♂️ Smooth movement and rotation with collision detection
- 🗺️ Minimap for easier navigation
- 📝 Configurable resolution and textures via configuration file
- 🎨 Custom floor and ceiling colors
- 🖥️ Built with MLX42 graphics library

## 🕹️ Controls
<details>
<summary><b>Game Controls</b></summary><br>
<p>Here are the controls implemented in cub3D:</p>

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `ESC` | Exit the game |
</details>

## 🗺️ Map Format
<details>
<summary><b>Map Configuration</b></summary><br>
<p>The map must be provided as a `.cub` file with the following format:</p>

```
NO ./path_to_north_texture.png
SO ./path_to_south_texture.png
WE ./path_to_west_texture.png
EA ./path_to_east_texture.png

F R,G,B    # Floor color (RGB values)
C R,G,B    # Ceiling color (RGB values)

# Map layout (0: empty space, 1: wall, N/S/E/W: player starting position and orientation)
111111
100001
1000N1
100001
111111
```

### Map Layout Rules
- The map must be surrounded by walls (1)
- Only one player starting position is allowed (N, S, E, or W)
- The map can contain spaces but must be rectangular
</details>

> [!NOTE]
> MLX42 is used instead of minilibX, and PNG files are used for textures instead of XPM.

## 🧮 Technical Implementation
<details>
<summary><b>Raycasting Engine Details</b></summary><br>
<p>This raycasting engine implements the following techniques:</p>

- Digital Differential Analysis (DDA) algorithm for ray casting
- Texture mapping with perspective correction
- Double buffering for smooth rendering
- Event-driven input handling
</details>

> [!WARNING]
> "You may question your understanding of 3D mathematics during this project"

<div align="center">
  <img src="https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExdXQ4NDZmMmhtYzlqYnFrM2Zkenl1d3J1MGVwcWQ5OHUzd25qODdneSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/26BRAfDqmQ0RogLwA/giphy.gif" width="400" alt="This is cub3D">
  <br>
  <i>A journey into early 3D game rendering</i><br><br><br>
</div>

---
<div align="center">
  <p>Made with ❤️ and lots of 📐 𝙼𝙰𝚃𝙷</p>
</div>
  
## Acknowledgements

- 42 School for the project requirements and framework [(CODAM MLX42)](https://github.com/codam-coding-college/MLX42)
- ID Software for the original Wolfenstein 3D raycasting concept
- [Lodev's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) for reference
