# so_long

The goal of this project is to create a small 2D top-down game using the MiniLibX graphics library. It provides a foundational understanding of 2D game loops, sprite rendering, window event handling, map parsing, and graph traversal algorithms like Flood Fill.

This project has been created as part of the 42 curriculum by [Svetlana Titovskaia](https://github.com/svetameanssun).

---

## 💡 Key Concepts
This project introduces the fundamentals of **2D game development** and **event-driven programming**. It helps refine skills in parsing and validating complex map files, loading XPM textures, handling keyboard/window inputs asynchronously, and verifying game solvability using graph algorithms before initialization.

---

## 🧠 Programming Concepts
* **Map Parsing & File Validation:** Reading `.ber` files, validating map enclosures (surrounded by walls `1`), checking required components (1 player `P`, 1 exit `E`, at least 1 collectible `C`), and verifying rectangular shape.
* **Path Solvability (Flood Fill Algorithm):** Using Depth-First Search (DFS) or Breadth-First Search (BFS) to guarantee that a valid path exists from the player spawn to all collectibles and the exit.
* **Window & Event Management:** Utilizing MiniLibX hooks (`mlx_hook`, `mlx_key_hook`) to handle keyboard movement (W, A, S, D / Arrows) and clean window closure (`ESC` or red close button).
* **Tilemap Rendering & Textures:** Converting `.xpm` assets into image buffers (`mlx_xpm_file_to_image`) and drawing a 2D tile grid to the window (`mlx_put_image_to_window`).
* **Game State & Move Counting:** Tracking player position, remaining collectibles, total step count (printed to stdout), and handling victory/loss conditions.

---

## 🛠️ Tech Stack
* **Language:** C (C99 Standard)
* **Graphics Library:** MiniLibX (X11 / AppKit / MLX42)
* **Assets:** XPM Textures
* **Build System:** Makefile (`all`, `clean`, `fclean`, `re`)
* **Version Control:** Git
* **Libraries:** `libft` / `get_next_line` (if linked)

---

## 🎯 Hard Skills
* **Graph Traversal Implementation:** Writing a custom Flood Fill algorithm to test map connectivity and reachability before launching the game window.
* **Asset & Window Memory Management:** Properly destroying image textures (`mlx_destroy_image`), windows (`mlx_destroy_window`), and freeing 2D arrays on exit with zero leaks.
* **Input Event Hooking:** Handling non-blocking user inputs and triggering frame updates without UI lag or freezes.
* **Grid-Based Collision Logic:** Preventing player movement into wall tiles (`1`) or premature exit interactions (`E`) before gathering all collectibles.

---

## 🤝 Soft Skills
* **User Experience & Feedback:** Displaying step counts clearly in the terminal and providing graceful error messages (`Error\n...`) for corrupted map files.
* **Edge Case Verification:** Handling empty files, non-rectangular maps, invalid characters, unreachable collectibles, and missing permissions.
* **Norminette Compliance:** Structuring clean, single-responsibility C functions while strictly adhering to 42's coding standard.

---

## 📁 Project Structure

```text
.
├── imgs
│   └── *.png
├── include
│   ├── so_long_bonus.h
│   └── so_long.h
├── lib
│   ├── ft_printf
│   │   ├── ft_printf.h
│   │   └── libftprintf.a
│   ├── libft
│   |    ├── libft.a
│   |    └── libft.h
|   └── MLX42
├── Makefile
├── maps
│   └── *.ber
├── obj
│   ├── bonus
│   └── mandatory
└── src
    ├── bonus
    │   ├── check_elements_bonus.c
    │   ├── check_matrix_bonus.c
    │   ├── check_matrix_utils_bonus.c
    │   ├── floodfill_bonus.c
    │   ├── free_all_bonus.c
    │   ├── get_next_line_bonus.c
    │   ├── get_next_line_utils_bonus.c
    │   ├── load_elements_bonus.c
    │   ├── load_images_bonus.c
    │   ├── manage_errors_bonus.c
    │   ├── map_to_matrix_bonus.c
    │   ├── my_hook_bonus.c
    │   ├── my_keys_bonus.c
    │   ├── show_and_delete_bonus.c
    │   ├── so_long_bonus.c
    │   └── update_game_bonus.c
    └── mandatory
        ├── check_elements.c
        ├── check_matrix.c
        ├── check_matrix_utils.c
        ├── floodfill.c
        ├── free_all.c
        ├── get_next_line.c
        ├── get_next_line_utils.c
        ├── load_elements.c
        ├── load_images.c
        ├── manage_errors.c
        ├── map_to_matrix.c
        ├── my_hook.c
        ├── my_keys.c
        ├── show_and_delete.c
        ├── so_long.c
        └── update_game.c
```

## 🎮 How to Play & Compilation

### Compilation
```bash
# Mandatory Part
make
./so_long maps/map.ber

# Bonus Part
make bonus
./so_long maps/map_bonus.ber
```

> ⚠️ **Note on Bonus Maps:** When compiled with `make bonus`, valid map files must contain the word `bonus` in their filename (e.g., `map_bonus.ber`, `bonus_level.ber`).

### Game Rules
* **Objective:** Collect all collectibles (`C`) placed across the map and reach the exit (`E`) in as few moves as possible.
* You cannot walk through walls (`1`).
* The exit (`E`) only unlocks once all collectibles have been gathered.
* Total move counts are printed directly to the terminal on every step.

### Controls

| Key / Input | Action |
| :--- | :--- |
| `W` / `↑` | Move Up |
| `S` / `↓` | Move Down |
| `A` / `←` | Move Left |
| `D` / `→` | Move Right |
| `ESC` / `[X]` | Cleanly exit the game |