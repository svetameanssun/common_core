# ft_printf

The goal of this project is to recreate the standard C library function `printf()`. It provides a deeper understanding of variadic functions, string formatting, number base conversions, and low-level I/O handling.

---

## 💡 Key Concepts

This project introduces the concept of **variadic functions** in C, which allow functions to accept a variable number of arguments. It helps refine skills in output formatting, variable argument handling (`stdarg.h`), and type conversion (such as converting integers and pointers to hexadecimal). Additionally, it reinforces low-level system calls like `write()`.

---

## 🧠 Programming Concepts
* **Variadic Arguments:** Working with `va_list`, `va_start`, `va_arg`, and `va_end`.
* **Type Conversion & Base Operations:** Converting numbers between decimal (base 10) and hexadecimal (base 16).
* **Buffer & Memory Management:** Efficiently handling string and character outputs to `stdout`.
* **Parsing & Specifier Handling:** Iterating over format strings to identify and process conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`).

---

## 🛠️ Technologies
* **Language:** C
* **Build System:** Makefile (`all`, `clean`, `fclean`, `re`)
* **Version Control:** Git
* **Libraries & Headers:** `stdarg.h`, `unistd.h`

---

## 🎯 Hard Skills
* **Variadic Function Implementation:** Using C macros to handle arbitrary numbers/types of arguments safely.
* **Low-Level Output Control:** Direct usage of the `write()` system call for character output.
* **Radix / Base Conversions:** Writing custom algorithm logic for hexadecimal memory address printing and pointer formatting (`%p`, `%x`, `%X`).
* **Return Value Tracking:** Accurately calculating and returning the total number of characters printed.

---

## 🤝 Soft Skills
* **Code Modularization:** Breaking down complex format-parsing logic into small, single-responsibility helper functions.
* **Rigor & Edge Case Handling:** Managing NULL pointers, extreme integer values (`INT_MIN`, `INT_MAX`), and invalid conversion specifiers.
* **Norminette Compliance:** Adhering strictly to 42's coding standards while maintaining readable, maintainable code.

---

## 📁 Project Structure

```text
.
├── Makefile
├── ft_check_format.c
├── ft_printf.c
├── ft_printf.h
├── ft_put_int.c
├── ft_put_int_unsign.c
├── ft_puthex.c
├── ft_putptr.c
└── ft_strchar.c

```
