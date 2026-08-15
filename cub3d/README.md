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
