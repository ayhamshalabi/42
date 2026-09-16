
*This activity has been created as part of the 42 curriculum by ayhshala.*

# Libft — Your Very First C Library

Libft is the very first project in the 42 curriculum. Its objective is to build a foundational static C library (`libft.a`) by reimplementing standard C library (`libc`) functions alongside essential string utilities and data structure algorithms (linked lists).

This library serves as the core utility toolkit that will be reused across future C projects in the 42 syllabus (such as *ft_printf*, *get_next_line*, *pipex*, and *minishell*).

---

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
  - [Prerequisites](#prerequisites)
  - [Compilation & Rules](#compilation--rules)
  - [Using Libft in Your Own Projects](#using-libft-in-your-own-projects)
- [Detailed Function Breakdown](#detailed-function-breakdown)
  - [Part 1: Libc Reimplementations (23 Functions)](#part-1-libc-reimplementations)
  - [Part 2: Additional Utility Functions (11 Functions)](#part-2-additional-utility-functions)
  - [Part 3: Linked List Manipulation (9 Functions)](#part-3-linked-list-manipulation)
- [Technical Highlights & Edge Cases](#technical-highlights--edge-cases)
- [Resources & AI Usage](#resources)
  - [References](#references)
  - [AI Usage Disclosure](#ai-usage-disclosure)

---

## Description

In C programming, beginner developers frequently encounter situations where standard functions are either forbidden or not readily accessible. Implementing these functions from scratch provides an in-depth understanding of:

1. **Low-Level Memory Architecture**: Navigating memory directly, understanding byte offsets, buffer limits, stack vs. heap allocations, and zero-leak memory management.
2. **Pointer Arithmetic**: Safely iterating through raw pointers, multi-pointer arrays (`char **`), and double pointers (`t_list **`).
3. **Data Structures**: Building and manipulating dynamic singly linked lists with generic data storage (`void *`).
4. **Code Quality & Norm Compliance**: Writing clean, modular C code adhering strictly to 42 Norm standards (no global variables, max 25 lines per function, max 5 functions per file).

---

## Instructions

### Prerequisites
- A Unix-based environment (Linux, macOS, or WSL on Windows).
- A C compiler (`cc` or `clang` or `gcc`).
- Standard build tools (`make` and `ar`).

### Compilation & Rules

The provided `Makefile` complies with all 42 requirements, compiling with flags `-Wall -Wextra -Werror` using `cc`, and generating the archive using `ar rcs`:

| Command | Action |
| :--- | :--- |
| `make` or `make all` | Compiles all 43 `.c` source files and packages them into `libft.a`. |
| `make clean` | Removes all temporary object files (`.o`). |
| `make fclean` | Removes all object files AND the compiled archive `libft.a`. |
| `make re` | Performs a clean rebuild from scratch (`fclean` followed by `all`). |

*Note: The `Makefile` does **not** relink if all object files and `libft.a` are already up to date.*

### Using Libft in Your Own Projects

1. Place `libft.a` and `libft.h` in your project directory (or include paths).
2. Include the header in your C file:

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hello from custom Libft!", 1);
	return (0);
}
```

3. Compile your project while linking against `libft.a`:
```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program
```

---

## Detailed Function Breakdown

The library consists of **43 functions** categorized into three parts:

### Part 1: Libc Reimplementations

Standard C functions reimplemented with the `ft_` prefix according to their system `man` pages:

#### Character Classification & Conversion
*Subject requirement: classification functions must return strictly `1` (true) or `0` (false).*
- [`ft_isalpha`](ft_isalpha.c): Checks whether a character is an alphabetic letter (`A`-`Z` or `a`-`z`).
- [`ft_isdigit`](ft_isdigit.c): Checks whether a character is a decimal digit (`0`-`9`).
- [`ft_isalnum`](ft_isalnum.c): Checks whether a character is alphanumeric (`isalpha` or `isdigit`).
- [`ft_isascii`](ft_isascii.c): Checks whether a character fits into the 7-bit ASCII table (0 to 127).
- [`ft_isprint`](ft_isprint.c): Checks whether a character is printable (including space, ASCII 32 to 126).
- [`ft_toupper`](ft_toupper.c): Converts a lowercase character to its uppercase equivalent.
- [`ft_tolower`](ft_tolower.c): Converts an uppercase character to its lowercase equivalent.

#### String Examination & Search
- [`ft_strlen`](ft_strlen.c): Computes and returns the number of characters in a string preceding the terminating NUL byte.
- [`ft_strchr`](ft_strchr.c): Locates the first occurrence of a character in a string (including the terminating `\0`).
- [`ft_strrchr`](ft_strrchr.c): Locates the last occurrence of a character in a string.
- [`ft_strncmp`](ft_strncmp.c): Compares up to `n` characters between two strings using unsigned comparison.
- [`ft_strnstr`](ft_strnstr.c): Locates the first occurrence of string `little` in string `big`, searching at most `len` characters.

#### Memory Manipulation
- [`ft_memset`](ft_memset.c): Fills the first `n` bytes of memory with a constant byte `c`.
- [`ft_bzero`](ft_bzero.c): Writes zeroed bytes (`\0`) into `n` bytes of the destination buffer.
- [`ft_memcpy`](ft_memcpy.c): Copies `n` bytes from `src` to `dest`. Dest and src must not overlap.
- [`ft_memmove`](ft_memmove.c): Safely copies `n` bytes between memory areas, handling overlapping memory correctly.
- [`ft_memchr`](ft_memchr.c): Scans the first `n` bytes of a memory block for the first instance of character `c`.
- [`ft_memcmp`](ft_memcmp.c): Compares byte sequences of two memory blocks.

#### Size-Bounded String Copying & Concatenation
- [`ft_strlcpy`](ft_strlcpy.c): Copies up to `size - 1` characters from `src` to `dst`, guaranteeing NUL-termination if `size > 0`. Returns total length of `src`.
- [`ft_strlcat`](ft_strlcat.c): Appends string `src` to `dst`, guaranteeing NUL-termination within `size`. Returns `initial dst length + src length`.

#### Conversion & Dynamic Memory
- [`ft_atoi`](ft_atoi.c): Converts the initial portion of a string to an `int`, ignoring leading whitespaces and handling signs.
- [`ft_calloc`](ft_calloc.c): Allocates memory for an array of `nmemb` elements of `size` bytes, zeroes all bytes, and guards against multiplication overflow. If `size` or `nmemb` is 0, returns a unique freeable pointer.
- [`ft_strdup`](ft_strdup.c): Allocates sufficient memory and makes a duplicate copy of string `s1`.

---

### Part 2: Additional Utility Functions

Special utility functions that are either non-standard or variations of existing libc routines:

#### Dynamic String Operations
- [`ft_substr`](ft_substr.c): Allocates and returns a substring from string `s`, starting at index `start` with maximum length `len`. Correctly bounds `len` to avoid over-allocation.
- [`ft_strjoin`](ft_strjoin.c): Allocates and returns a new string formed by concatenating prefix `s1` and suffix `s2`.
- [`ft_strtrim`](ft_strtrim.c): Allocates and returns a copy of `s1` with all prefix and suffix characters present in `set` stripped away.
- [`ft_split`](ft_split.c): Splits string `s` into a NULL-terminated array of dynamically allocated strings using character `c` as delimiter. Safely frees previously allocated strings on allocation failure.
- [`ft_itoa`](ft_itoa.c): Converts an `int` into a dynamically allocated string, accurately handling negative numbers and `INT_MIN`.

#### String Iterators & Modifiers
- [`ft_strmapi`](ft_strmapi.c): Applies function `f` to each character of string `s` (with its index) to build and return a new mapped string.
- [`ft_striteri`](ft_striteri.c): Applies function `f` to each character of string `s` (with its index) in-place by passing its pointer.

#### File Descriptor Output
- [`ft_putchar_fd`](ft_putchar_fd.c): Writes a single character `c` to the specified file descriptor `fd`.
- [`ft_putstr_fd`](ft_putstr_fd.c): Writes an entire string `s` to the specified file descriptor `fd`.
- [`ft_putendl_fd`](ft_putendl_fd.c): Writes string `s` followed by a newline `\n` to the specified file descriptor `fd`.
- [`ft_putnbr_fd`](ft_putnbr_fd.c): Writes integer `n` to the specified file descriptor `fd` (handles negative and `INT_MIN`).

---

### Part 3: Linked List Manipulation

In **Version 1.3** of the subject, linked lists are part of the **Mandatory** section. The structure is declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

#### List Functions
- [`ft_lstnew`](ft_lstnew.c): Creates a new list node with `content` set to the passed value and `next` set to `NULL`.
- [`ft_lstadd_front`](ft_lstadd_front.c): Adds node `new` at the beginning of list `*lst`.
- [`ft_lstsize`](ft_lstsize.c): Counts and returns the total number of nodes in the list.
- [`ft_lstlast`](ft_lstlast.c): Returns a pointer to the final node in the list.
- [`ft_lstadd_back`](ft_lstadd_back.c): Appends node `new` at the end of list `*lst`.
- [`ft_lstdelone`](ft_lstdelone.c): Frees the content of the node using the function pointer `del`, then frees the node itself.
- [`ft_lstclear`](ft_lstclear.c): Iterates through the list, deletes and frees all nodes using `del` and `free`, and sets the list head pointer to `NULL`.
- [`ft_lstiter`](ft_lstiter.c): Iterates through the list and invokes function `f` on the content of every node.
- [`ft_lstmap`](ft_lstmap.c): Iterates through the list, applies `f` to each node's content, and builds a new mapped list. Cleans up all memory with `del` if any allocation fails.

---

## Technical Highlights & Edge Cases

This implementation specifically handles complex boundary conditions and edge cases tested during 42 automated evaluations (Francinette, libft-unit-test):

| Function | Challenge / Edge Case | How It Is Handled |
| :--- | :--- | :--- |
| **`ft_memmove`** | Memory overlap & pointer underflow | Compares pointers: copies forward if `dest < src`, backward if `dest > src`. Checks `if (n == 0 \|\| dest == src)` first to prevent `(n - 1)` unsigned underflow. |
| **`ft_memcpy`** | Null pointer input | Guards against `dest == NULL && src == NULL` to avoid segmentation fault when `n > 0`. |
| **`ft_calloc`** | Zero elements & integer overflow | Protects against `size * nmemb` multiplication overflow via `SIZE_MAX / nmemb`. If `size` or `nmemb` is 0, allocates 1 byte to return a unique freeable address as mandated by the subject. |
| **`ft_atoi` / `ft_itoa`** | `INT_MIN` (`-2147483648`) | In 32-bit signed integers, negating `INT_MIN` overflows. Handled safely by casting to a 64-bit `long` accumulator before sign multiplication or string conversion. |
| **`ft_substr`** | Unbounded length requests | If caller specifies `len` greater than the remaining string length, `len` is dynamically capped to `strlen(s) - start` to avoid allocating gigabytes of unused memory. |
| **`ft_split`** | Allocation failure during processing | If `malloc` fails while creating word $k$ of $N$, helper `free_res` cleans up all previously allocated words $0 \dots k-1$ and frees the pointer array before returning `NULL`. |

---

## Resources

### References
- **Linux Programmer's Manual**: System man pages (`man 3 malloc`, `man 3 memcpy`, `man 3 memmove`, `man 3 strnstr`, etc.).
- **Brian W. Kernighan & Dennis M. Ritchie**: *The C Programming Language (2nd Edition)*.
- **BSD Libc**: Reference implementations for BSD-specific functions (`strlcpy`, `strlcat`, `bzero`).
- **42 School Norm Guide**: Formatting, structure, and naming conventions.

### AI Usage Disclosure
In accordance with the 42 curriculum AI guidelines (Subject Chapter 3 & Chapter 5):
- **Role of AI**: AI assistance was utilized strictly as an interactive peer reviewer, debugger, and testing consultant.
- **Specific Tasks**:
  - **Edge-Case Auditing**: Identifying edge-case vulnerabilities (such as unsigned underflow in `ft_memmove`, integer overflow on `INT_MIN` in `ft_atoi`, and buffer length capping in `ft_substr`).
  - **Review Preparation**: Generating mock peer-evaluation defense questions and test cases in `main.c`.
  - **Code Ownership**: All function implementations, logic, algorithms, and 42 Norm compliance were analyzed, written, and verified directly by the author.
