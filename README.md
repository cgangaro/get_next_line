# Get Next Line

Get Next Line is a C project that involves creating a function to read lines from a file descriptor. The aim is to develop a useful function and understand the concept of static variables in C.

## Guidelines
- Code must be written in C.
- Functions do not cause unexpected crashes (segfault, bus error, etc.).
- All allocated memory is freed; no memory leaks.
- Successive calls to `get_next_line` read the entire file line by line.
- Returns the line read followed by `\n` if it exists.
- Returns `NULL` if there is nothing more to read or an error occurs.
- Handles standard input (stdin) as well.
- Header file `get_next_line.h` includes the function prototype.
- Additional utility functions are in `get_next_line_utils.c`.

Project made with ❤️ by [YourName](https://github.com/YourName).