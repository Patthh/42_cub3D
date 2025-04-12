# cub3D

A Wolfenstein 3D-inspired raycasting engine implemented in C as part of the 42 School curriculum.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Map Format](#map-format)
- [Project Structure](#project-structure)
- [Technical Implementation](#technical-implementation)
- [Contributors](#contributors)
- [Acknowledgements](#acknowledgements)

## Overview

This project is an implementation of a simplified raycasting engine, similar to the one used in Wolfenstein 3D. It creates a 3D-like environment from a 2D map, allowing the player to navigate through corridors and rooms in a first-person perspective.

## Features

- Textured walls with different textures for North, South, East, and West facing walls
- Smooth movement and rotation
- Minimap for navigation
- Collision detection
- Configurable resolution and textures via configuration file
- Floor and ceiling colors

## Installation

### Prerequisites
- GCC compiler
- Make
- MinilibX library (included)
- X11 development libraries (for Linux)

### Build
Clone the repository and compile using make:

```bash
git clone https://github.com/Patthh/42_cub3D.git
cd 42_cub3D
make
```

## Usage

Run the program with a map file:

```bash
./cub3D maps/map.cub
```

## Controls

- `W` - Move forward
- `S` - Move backward
- `A` - Strafe left
- `D` - Strafe right
- `←` - Rotate camera left
- `→` - Rotate camera right
- `ESC` - Exit the game

## Map Format

The map must be provided as a `.cub` file with the following format:

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

## Project Structure

```
.
├── includes/           # Header files
├── libft/              # Custom C library
├── maps/               # Map files
├── mlx/                # MinilibX library
├── src/                # Source files
│   ├── init/          # Initialization functions
│   ├── parse/         # Map parsing
│   ├── ray/           # Raycasting implementation
│   ├── render/        # Rendering functions
│   └── utils/         # Utility functions
├── textures/           # Wall texture files
├── Makefile            # Build instructions
└── README.md           # This file
```

## Technical Implementation

This raycasting engine implements the following techniques:

- Digital Differential Analysis (DDA) algorithm for ray casting
- Texture mapping with perspective correction
- Double buffering for smooth rendering
- Event-driven input handling

## Contributors

- [Patthh](https://github.com/Patthh)
- [Тони](https://github.com/42Monkey)
  
## Acknowledgements

- 42 School for the project requirements and framework(CODAM MLX42)
- ID Software for the original Wolfenstein 3D raycasting concept
- [Lodev's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) for reference
