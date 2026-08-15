# push_swap

The goal of this project is to sort a stack of integers using a secondary stack and a restricted set of stack instructions, producing the shortest possible sequence of operations. It provides a deep understanding of sorting algorithms, complexity analysis ($O(n^2)$ vs. $O(n \log n)$), stack data structures, and algorithmic optimization.

This project has been created as part of the 42 curriculum by [Svetlana Titovskaia](https://github.com/svetameanssun).

---

## 💡 Key Concepts
This project introduces **algorithmic efficiency** and **data structure manipulation**. It helps refine skills in evaluating computational complexity, choosing optimal sorting strategies based on dataset size, and managing low-level pointer-based memory structures under strict operational constraints.

---

## 🧠 Programming Concepts
* **Stack Data Structures:** Implementing and manipulating two stacks (`a` and `b`) using linked lists or dynamic arrays.
* **Instruction Set Implementation:** Executing low-level stack operations:
  * **Swap:** `sa`, `sb`, `ss`
  * **Push:** `pa`, `pb`
  * **Rotate:** `ra`, `rb`, `rr`
  * **Reverse Rotate:** `rra`, `rrb`, `rrr`
* **Sorting Algorithms & Optimization:** Designing custom sorting logic (e.g., Turk algorithm, Radix sort, or Chunking) to achieve minimum instruction counts for 3, 5, 100, and 500 numbers.
* **Input Parsing & Validation:** Handling command-line arguments, string-to-integer conversion (`ft_atoi`), checking for non-numeric characters, duplicate values, and integer overflows (`INT_MIN`, `INT_MAX`).

---

## 🛠️ Tech Stack
* **Language:** C (C99 Standard)
* **Build System:** Makefile (`all`, `clean`, `fclean`, `re`)
* **Version Control:** Git
* **Testing & Benchmarking:** Push_swap Visualizer, Valgrind, `checker` binary

---

## 🎯 Hard Skills
* **Algorithm Complexity Optimization:** Writing logic to consistently pass 42 performance benchmarks (< 700 ops for 100 numbers, < 5500 ops for 500 numbers).
* **Pointer & Memory Management:** Safely managing dynamic memory allocations for linked list nodes with zero leaks.
* **Data Validation & Parsing:** Building clean input validation to catch invalid arguments before performing operations.
* **Instruction Cost Calculation:** Calculating target node positioning costs in Stack B to perform the cheapest moves first.

---

## 🤝 Soft Skills
* **Benchmarking & Analysis:** Testing algorithms against large randomized datasets to identify performance bottlenecks.
* **Edge Case Engineering:** Handling pre-sorted arrays, single-element stacks, negative numbers, and max/min limits without crashing.
* **Norminette Compliance:** Writing modular, maintainable C code adhering strictly to 42's formatting standards.

---

## 📁 Project Structure

```text
.
├── Makefile
└── src
    ├── args_to_stack.c
    ├── chars_and_strings.c
    ├── free_and_error.c
    ├── init_stacks.c
    ├── input_check.c
    ├── min_max_size.c
    ├── numbers.c
    ├── push_swap.c
    ├── push_swap.h
    ├── set_costs.c
    ├── sort_elements.c
    ├── sorting_movements.c
    ├── sorting_movements_double.c
    ├── sort_three_elements_utils.c
    └── tagets_and_positions.c
