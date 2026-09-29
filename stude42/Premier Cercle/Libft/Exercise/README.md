*This activity has been created as part of the 42 curriculum by <wineto-m>.*

# Libft

## Description

Libft is a custom C library developed as part of the 42 curriculum.
The goal of this project is to reimplement a set of standard C library functions, as well as additional utility functions, in order to better understand how they work internally.

This library serves as a foundational toolkit that will be reused in future projects throughout the curriculum.

## Features

The library is divided into three main parts:

### Part 1 – Libc Functions

Reimplementation of standard C functions, including:

* Character checks (`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, etc.)
* Memory manipulation (`ft_memset`, `ft_bzero`, `ft_memcpy`, etc.)
* String handling (`ft_strlen`, `ft_strlcpy`, `ft_strncmp`, etc.)
* Conversion (`ft_atoi`)
* Allocation (`ft_calloc`, `ft_strdup`)

### Part 2 – Additional Functions

Custom utility functions:

* `ft_substr` – Extract substring
* `ft_strjoin` – Concatenate strings
* `ft_strtrim` – Trim characters
* `ft_split` – Split string by delimiter
* `ft_itoa` – Convert integer to string
* `ft_strmapi` / `ft_striteri` – Apply function to string
* Output functions (`ft_putchar_fd`, `ft_putstr_fd`, etc.)

### Part 3 – Linked List

Implementation of a simple linked list API:

* Node creation (`ft_lstnew`)
* Add/remove elements (`ft_lstadd_front`, `ft_lstadd_back`)
* Traversal (`ft_lstiter`, `ft_lstmap`)
* Memory management (`ft_lstdelone`, `ft_lstclear`)
* Utilities (`ft_lstsize`, `ft_lstlast`)

## Installation

Clone the repository:

```bash
git clone https://github.com/<your_username>/libft.git
cd libft
```

Compile the library:

```bash
make
```

This will generate:

```
libft.a
```

## Usage

Include the header in your C files:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lft -o program
```

## Makefile Rules

* `make` or `make all` – Compile the library
* `make clean` – Remove object files
* `make fclean` – Remove object files and library
* `make re` – Recompile everything

## Technical Constraints

* Written in C
* Compiled with `-Wall -Wextra -Werror`
* No memory leaks allowed
* No global variables
* Uses `ar` to create the library
* All helper functions are declared `static`

## Resources

* Manual pages (`man strlen`, `man malloc`, etc.)
* The C Programming Language – Kernighan & Ritchie
* GNU C Library documentation
* 42 Intranet resources

### AI Usage

AI was used as a support tool for:

* Understanding function specifications
* Clarifying edge cases and expected behaviors

---

