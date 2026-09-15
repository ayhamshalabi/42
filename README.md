*This activity has been created as part of the 42 curriculum by ayhshala.*

# Libft - Your Very First Own C Library

## Description
**Libft** is the foundational project of the 42 coding school curriculum. In C programming, many standard utility functions provided by the C Standard Library (`libc`) are essential for memory management, string manipulation, and data structure handling. The purpose of this project is to recreate a wide variety of these standard functions from scratch, along with additional utility functions and linked list manipulation operations.

Through building this static library (`libft.a`), the project develops a deep, fundamental understanding of:
- Memory management (stack vs. heap allocations, byte manipulation, and memory leak prevention).
- Pointer arithmetic, memory boundaries, and buffer safety.
- Data structures (singly linked lists using generic pointers `void *`).
- Compilation pipelines, Makefile automation, and static library archiving (`ar rcs`).

All code is strictly written in accordance with the **42 Norm**, without global variables, and adheres to zero-leak standards under `valgrind`.

---

## Instructions

### Compilation
The library is compiled using `make`. All files are compiled with `cc` using the `-Wall -Wextra -Werror` flags:

```bash
# Build the library libft.a
make

# Clean up object files (.o)
make clean

# Remove object files and the compiled library
make fclean

# Clean and re-build from scratch
make re
```

### Linking with Your Own Project
To use `libft.a` in another C project, include `libft.h` in your source code and link the archive during compilation:

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hello from my custom Libft!", 1);
	return (0);
}
```

Compile and link:
```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program
```

---

## Resources

### References and Documentation
- Linux Programmer's Manual (`man 3 malloc`, `man 3 memset`, `man 3 memcpy`, `man 3 memmove`, `man 3 strlcpy`, `man 3 strlcat`, etc.)
- *The C Programming Language* (2nd Edition) – Brian W. Kernighan & Dennis M. Ritchie
- Apple Open Source Libc / OpenBSD source code references for `strlcpy` and `strlcat` standards.
- 42 School Norminette documentation (v3).

### AI Usage Disclosure
In accordance with 42 curriculum AI guidelines (Chapters 3 and 5):
- **Purpose**: AI was utilized as an auxiliary learning and peer-review simulation tool.
- **Tasks & Parts**:
  - **Edge-Case Auditing**: AI was consulted to review potential edge-case vulnerabilities in Part 1 and Part 2 (e.g., verifying integer overflow risks on `INT_MIN` in `ft_atoi`, pointer underflow scenarios when `n == 0` in `ft_memmove`, and memory allocation bounds for `ft_substr`).
  - **Review Preparation**: AI was used to generate peer-evaluation interview questions and edge-case verification test programs.
  - **Core Logic & Implementation**: All function implementations, algorithmic structure, logic, and Norm conformance were understood, analyzed, and written directly by the author.

---

## Detailed Description of the Library

The library contains **43 functions** divided into three distinct parts:

### Part 1: Libc Reimplementations
Recreations of essential standard C library functions prefixed with `ft_`:

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_isalpha` | `int ft_isalpha(int c);` | Returns 1 if character is alphabetic, 0 otherwise. |
| `ft_isdigit` | `int ft_isdigit(int c);` | Returns 1 if character is a digit (0-9), 0 otherwise. |
| `ft_isalnum` | `int ft_isalnum(int c);` | Returns 1 if character is alphanumeric, 0 otherwise. |
| `ft_isascii` | `int ft_isascii(int c);` | Returns 1 if character is in ASCII table (0-127), 0 otherwise. |
| `ft_isprint` | `int ft_isprint(int c);` | Returns 1 if character is printable (including space), 0 otherwise. |
| `ft_strlen` | `size_t ft_strlen(const char *s);` | Calculates and returns the length of a string. |
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n);` | Fills the first `n` bytes of memory area with constant byte `c`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n);` | Erases the data in the `n` bytes of memory by writing zeroes (`\0`). |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes from `src` to `dest` (memory must not overlap). |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n);` | Safely copies `n` bytes between memory areas, handling overlaps. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Size-bounded string copy; guarantees NUL-termination if `size > 0`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size);` | Size-bounded string concatenation; guarantees NUL-termination. |
| `ft_toupper` | `int ft_toupper(int c);` | Converts lowercase character to uppercase. |
| `ft_tolower` | `int ft_tolower(int c);` | Converts uppercase character to lowercase. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c);` | Locates first occurrence of character `c` in string `s`. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c);` | Locates last occurrence of character `c` in string `s`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares first `n` characters of two strings as unsigned char. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n);` | Scans `n` bytes of memory for character `c`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares `n` bytes of two memory areas as unsigned char. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len);` | Locates substring `little` in string `big` within length `len`. |
| `ft_atoi` | `int ft_atoi(const char *nptr);` | Converts initial portion of string to an integer. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size);` | Allocates memory for array and zeroes it; guards against overflow. |
| `ft_strdup` | `char *ft_strdup(const char *s1);` | Duplicates string `s1` by allocating dynamic memory with malloc. |

### Part 2: Additional Utility Functions
Custom functions for string manipulations and formatted file descriptor outputs:

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates and returns a substring from string `s` starting at index `start`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2);` | Allocates and returns a new string which is the concatenation of `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set);` | Allocates and returns a copy of `s1` with prefix/suffix chars in `set` removed. |
| `ft_split` | `char **ft_split(char const *s, char c);` | Splits string `s` into an array of strings delimited by character `c`. |
| `ft_itoa` | `char *ft_itoa(int n);` | Converts integer `n` into a null-terminated string (handles negative and `INT_MIN`). |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Creates new string by applying `f` to each character of `s`. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *));` | Modifies string `s` in-place by passing address of each character to `f`. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);` | Outputs character `c` to the specified file descriptor. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd);` | Outputs string `s` to the specified file descriptor. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);` | Outputs string `s` followed by newline `\n` to the specified file descriptor. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd);` | Outputs integer `n` to the specified file descriptor (handles negative and `INT_MIN`). |

### Part 3: Linked List Functions (Mandatory in v1.3)
Operations to manipulate singly linked lists defined by `t_list`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Allocates and creates a new node with `content` and `next = NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Prepends node `new` at the beginning of list `*lst`. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst);` | Counts and returns the number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Returns a pointer to the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Appends node `new` at the end of list `*lst`. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees node's content using `del`, then frees node (does not free `next`). |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees node and all successive nodes; sets `*lst = NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates over list and applies function `f` to the content of each node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Iterates list and maps each node's content to a new list; frees on error. |
