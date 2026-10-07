# get_next_line

`get_next_line` is a C function that reads a file **one line at a time**:

```c
char *get_next_line(int fd);
```

Each call returns the next line of the file (including the `\n`), or `NULL` when the file ends or an error occurs. I built it from scratch using only `read`, `malloc` and `free`, without any standard library helpers.

The project is part of the 42 curriculum, a peer-reviewed, project-based software engineering programme. You can find the full project brief in [1.2_get_next_line.pdf](https://github.com/marianne-p/get_next_line_42/blob/main/1.2_get_next_line.pdf).

## How it works

- The file is read in chunks of `BUFFER_SIZE` bytes, a value set at compile time (`-D BUFFER_SIZE=42`), until a newline is found or the file ends.
- The function returns everything up to and including the newline. The remaining text is kept in a `static` buffer, ready for the next call.
- **Bonus:** it can handle up to 1024 open files at once. Each file keeps its own leftover buffer, so you can switch between files freely between calls.

## Skills demonstrated

- **Streaming / buffered I/O:** processing data in small chunks rather than loading a whole file into memory. This is the same idea behind reading large CSVs or log files in chunks (pandas `chunksize`, Python file iterators, data pipelines).
- **Keeping state between calls:** a `static` variable remembers where the previous call left off, much like a Python generator or iterator.
- **Manual memory management:** every buffer is allocated and freed by hand, including on error paths.
- **Edge cases:** a final line without a newline, empty files, read errors, invalid file descriptors, and buffer sizes from 1 byte to very large.
- **Low-level understanding:** a hands-on look at what a high-level `readline()` does under the hood.

## Usage

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```

## My result:
<img width="888" height="222" alt="image" src="https://github.com/user-attachments/assets/29b23015-a0f2-4127-bfa7-8aec93a5cff0" />
