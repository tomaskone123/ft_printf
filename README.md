# ft_printf

## Overview
The `ft_printf` project is a custom implementation of the standard C `printf` function. This project replicates the behavior of `printf`, handling formatted output to the standard output. It was created as part of the 42 Network curriculum and serves as an introduction to advanced C programming concepts such as variadic functions, modular design, and memory management.

## Features
The `ft_printf` function supports:

- Basic conversion specifiers:
  - `%c` - Character
  - `%s` - String
  - `%d` or `%i` - Signed decimal integer
  - `%u` - Unsigned decimal integer
  - `%x` - Unsigned hexadecimal integer (lowercase)
  - `%X` - Unsigned hexadecimal integer (uppercase)
  - `%p` - Pointer address
  - `%%` - Percent sign

- Correct handling of edge cases and special values.
- Modular and clean code structure for easier debugging and extension.

## Function Prototype
```c
int ft_printf(const char *format, ...);
```

## Usage
1. Include the `ft_printf.h` header in your project.
2. Compile the library (if provided as a standalone `.a` file) or include the source files in your project.
3. Call `ft_printf` in your code just like the standard `printf` function.

### Example
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", main);
    return 0;
}
```

## Implementation Details
- **Variadic Functions**: `ft_printf` uses `va_list`, `va_start`, `va_arg`, and `va_end` macros to handle a variable number of arguments.
- **Parsing and Dispatching**: The format string is parsed character by character, and appropriate functions are called based on the conversion specifier.
- **Helper Functions**: A collection of helper functions are used to handle individual specifiers, buffer management, and error handling.

## Limitations
- Does not fully implement all specifiers and flags from the standard `printf` (e.g., width, precision, and length modifiers may be missing).
- No support for floating-point conversions (`%f`, `%e`, `%g`).

## Compilation
To compile the project, use the provided Makefile:

```bash
make
```

This will generate the `libftprintf.a` library file. You can link it to your project using:

```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o program
```


