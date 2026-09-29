*This activity has been created as part of the 42 curriculum by wineto-m.*

# get_next_line

## Description

`get_next_line` is a C function that reads a single line from a file descriptor each time it is called. The goal is to return the next line from a file, standard input, or any valid file descriptor, including the newline character when present. It is designed to be called in a loop to read an entire file line by line without loading it all into memory at once.

The implementation uses a linked list as a buffer (stash) to store data read between calls, allowing the function to handle any buffer size and persist state across multiple calls.

## Instructions

### Compilation

Clone the repository and compile with the provided Makefile:

```bash
git clone <repository_url>
cd get_next_line
make
```

This will produce `get_next_line.a`, a static library you can link against your project.

### Usage

Include the header in your source file:

```c
#include "get_next_line.h"
```

Call `get_next_line` in a loop:

```c
int     fd;
char    *line;

fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Compilation flags

The buffer size can be overridden at compile time:

```bash
cc -D BUFFER_SIZE=64 your_file.c get_next_line.a
```

## Resources

- [Linux man page — read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux man page — open(2)](https://man7.org/linux/man-pages/man2/open.2.html)
- [Understanding static variables in C](https://en.cppreference.com/w/c/language/storage_duration)
- [Linked lists in C — GeeksForGeeks](https://www.geeksforgeeks.org/linked-list-in-c/)

### AI usage

Claude (Anthropic) was used throughout this project as a debugging and guidance tool. It helped with:
- Identifying compilation errors and type mismatches
- Understanding the logic behind the stash management between calls
- Structuring the code into single-responsibility functions
- Writing the Makefile

No function code was generated directly by AI — all implementations were written by the student, with AI providing explanations and pointing out errors step by step.
