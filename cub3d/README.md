# cub3D

The goal of this project is to create a dynamic 3D graphical representation of the inside of a maze from a first-person perspective using raycasting principles, inspired by the world-famous 90s game *Wolfenstein 3D*. It provides a deep understanding of computer graphics, 2D-to-3D projection mathematics, window event handling, and low-level pixel buffer rendering.

---

## 💡 Key Concepts
This project introduces the fundamentals of **computer graphics** and **real-time rendering engines**. It helps refine skills in vector mathematics, trigonometric calculations, map file parsing, frame buffer manipulation, and processing hardware inputs (keyboard/mouse) using the MiniLibX library.

---

## 🧠 Programming Concepts
* **Raycasting & DDA Algorithm:** Using the Digital Differential Analysis (DDA) algorithm to cast rays from the player's position across a 2D grid matrix, calculating exact line-grid intersections and perpendicular wall distances to prevent fish-eye distortion.
* **Texture Mapping & Pixel Rendering:** Scaling 2D texture images onto projected 3D wall slices, calculating precise texture X/Y coordinates, and rendering ceiling/floor color gradients directly to an image buffer.
* **Configuration Parsing & Map Validation:** Parsing `.cub` map files to extract texture file paths, RGB color codes, and validating that the map matrix is fully enclosed by walls (handling spaces, invalid characters, and multiple spawn points).
* **Player Movement & Collision Physics:** Calculating player position vectors, direction vectors, camera plane vectors, and implementing collision detection to prevent clipping through wall geometry.

---

## 🛠️ Tech Stack
* **Language:** C (C99 Standard)
* **Graphics Library:** MiniLibX (X11 / AppKit / MLX42)
* **Mathematics:** Trigonometry & Vector Math (`<math.h>`)
* **Build System:** Makefile (`all`, `clean`, `fclean`, `re`)
* **Version Control:** Git

---

## 🎯 Hard Skills
* **3D Engine Architecture:** Implementing a first-person raycasting graphics loop running at high frame rates.
* **Direct Framebuffer Writing:** Writing ARGB/RGBA color pixels directly into memory buffers before pushing complete images to the window to eliminate screen tearing and flickering.
* **Robust File & Map Parsing:** Building a resilient parser capable of detecting unclosed walls, missing elements, invalid file extensions, and corrupted texture paths.
* **Input Event Hooking:** Handling smooth continuous keyboard movement (W, A, S, D), camera rotations (Left/Right arrows), and window close events (`ESC`, red cross button).

---

## 🤝 Soft Skills
* **Mathematics Translation:** Applying mathematical concepts (FOV calculations, vector rotation matrices, line intersections) into clean C functions.
* **Performance Optimization:** Eliminating unnecessary floating-point operations and heavy trigonometric function calls inside the main render loop.
* **Norminette & Memory Management:** Adhering to 42's coding standard while ensuring zero memory leaks and proper destruction of MiniLibX images/windows on exit.

---

## 📁 Project Structure

```text
.
├── MLX42
├── checker_map
│   ├── checker_borders.c
│   ├── checker_inside.c
│   └── checker_spaces.c
├── full_window
│   ├── callback.c
│   ├── ft_calculations.c
│   ├── ft_movements.c
│   ├── ft_painting.c
│   ├── ft_player.c
│   ├── ft_textures_mlx.c
│   └── rays.c
├── imgs
│   ├── baba_yaga.png
│   ├── leshyi.png
│   ├── rana.png
│   ├── vasilisa.png
│   ├── wooden_wall_chopper.png
│   ├── wooden_wall_monkey.png
│   ├── wooden_wall_nami.png
│   └── wooden_wall_nico.png
├── includes
│   ├── colors.h
│   ├── cub3d.h
│   ├── ft_printf.h
│   ├── get_next_line_bonus.h
│   ├── get_next_line.h
│   ├── libft.h
│   └── macro.h
├── init
│   ├── init_structures.c
│   └── init_walls_and_rays.c
├── libs
│   ├── gnl
│   │   └── libgnl.a
│   ├── libft
│   │   └── libft.a
│   └── printf
│       └── libftprintf.a
├── Makefile
├── maps
│   ├── map_42_1.cub
│   ├── map_42_2.cub
│   ├── map_42_3.cub
│   ├── map_42_4.cub
│   ├── map_art.cub
│   ├── map_military2.cub
│   ├── map_military.cub
│   ├── map_one_piece2.cub
│   ├── map_one_piece.cub
│   ├── map_one_piece_inverted.cub
│   ├── map_one_piece_non_inverted.cub
│   ├── map_profiles_DR.cub
│   ├── map_vangogh_0.cub
│   ├── map_vangogh_1.cub
│   ├── map_walls_0.cub
│   ├── map_walls_1.cub
│   └── map_walls_2.cub
├── maps_non_valids
│   ├── bad_double_color.cub
│   ├── bad_extension.cuv
│   ├── bad_wall_first.cub
│   ├── bad_wall_last.cub
│   ├── bad_wrong_f_color.cub
│   ├── color_missing.cub
│   ├── color_missing_rgb.cub
│   ├── color_none.cub
│   ├── file_letter_end.cub
│   ├── filetype_missing
│   ├── filetype_wrong.buc
│   ├── map_bad_id.cub
│   ├── map_bad_path.cub
│   ├── map_empty.cub
│   ├── map_first.cub
│   ├── map_middle.cub
│   ├── map_missing.cub
│   ├── map_only.cub
│   ├── map_rgb_err.cub
│   ├── map_splittered.cub
│   ├── map_too_small.cub
│   ├── player_multiple.cub
│   ├── player_none.cub
│   ├── player_on_edge.cub
│   ├── test_double_path.cub
│   ├── test_no_path.cub
│   ├── test_pos_left._xpm.cub
│   ├── test_tabs.cub
│   ├── test_wrong_symbols.cub
│   └── wall_open.cub
├── obj
├── parser
│   └── parser.c
├── play
│   └── main.c
└── read_map
    ├── checker_2.c
    ├── checker.c
    ├── error.c
    ├── free.c
    ├── manage_color.c
    ├── map.c
    ├── textures.c
    ├── update_map.c
    ├── utils_2.c
    └── utils.c
```

## 🎮 How to Play & Controls

### Compilation & Execution
```bash
# Compile the project
make

# Run the game with a valid .cub map file
./cub3D maps/map.cub
```
### Controls

| Key / Input | Action |
| :--- | :--- |
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` / `→` | Rotate camera view left / right |
| `ESC` / `[X]` | Cleanly exit the game |
