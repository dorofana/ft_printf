# ft_printf
This project has been created as part of the 42 curriculum by _adorofei_. If you have any questions, feel free to reach out via email: adorofei@student.42prague.com.

## About the Project

This project is a custom implementation of the standard C library `printf` function. It is part of the core curriculum at 42 School and introduces the concept of variadic functions in C.

This implementation mimics the behavior of the original `printf` for the following mandatory format specifiers:

`%c`: Prints a single character.

`%s`: Prints a string. Handles `NULL` pointers gracefully.

`%p`: The `void *` pointer argument is printed in hexadecimal format.

`%d`: Prints a decimal (base 10) number.

`%i`: Prints an integer in base 10.

`%u`: Prints an unsigned decimal (base 10) number.

`%x`: Prints a number in hexadecimal (base 16) lowercase format.

`%X`: Prints a number in hexadecimal (base 16) uppercase format.

`%%`: Prints a percent sign.

## Features

- **Variadic Functions**: Extensive use of stdarg.h (`va_start`, `va_arg`, `va_copy`, `va_end`) to process an unknown number of arguments.

- **Error Handling**: Strict tracking of write return values. If any printing fails, the function stops and correctly returns -1.

- **Norminette Compliant**: Written according to the strict 42 coding standard.

## Bonus Features

This implementation also supports the following formatting flags:

`+`: Forces a plus sign (`+`) to be used on positive numbers (`%d`, `%i`).

` `: (Space) Leaves a blank space before a positive number (`%d`, `%i`).

`#`: Adds a `0x` or `0X` prefix to non-zero hexadecimal values (`%x`, `%X`).

## Technical Requirements

- All code is written in C.
- The code strictly complies with the **Norminette** formatting rules.
- All functions are compiled with the `-Wall -Wextra -Werror` flags using the `cc` compiler.
- The Makefile contains the required rules such as `$(NAME)`, `all`, `clean`, `fclean`, `re` and `bonus`.
- The library is compiled properly without relinking.
- Memory is managed correctly; there are no memory leaks.

## Good to Know

To ensure the project meets all expectations, the subject.pdf file was used as a reference. You can find this file on the project's main page; it contains all the necessary instructions and requirements.

Additionally, AI tools were used to help write a clear description for the project!

## Usage (Makefile)

The project includes a `Makefile` to automate the compilation of the `libftprintf.a` static library. The following rules are available:

- `make` or `make all` — compiles the mandatory part of the project.
- `make clean` — removes object files (`.o`).
- `make fclean` — removes object files and the `libftprintf.a` library.
- `make re` — performs a full recompilation (`fclean` + `all`).
- `make bonus` — compiles the library including the bonus linked list functions.

## How to Include in Your Code

To use this library in your future projects, include the header file in your `.c` files:

```c
#include "ft_printf.h"
```

And compile your code with the compiled library:

```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```