# get_next_line

A C function that reads a file **one line at a time**:

```c
char *get_next_line(int fd);
```

Each call returns the next line from the file (including the `\n`), or `NULL` at end of file or on error. It is built from scratch using only `read`, `malloc` and `free`, with no standard library helpers. The project is part of the 42 curriculum, a peer-reviewed, project-based software engineering programme.

## How it works

- Reads the file in chunks of `BUFFER_SIZE` bytes, set at compile time (`-D BUFFER_SIZE=42`), until it finds a newline or reaches the end of the file.
- Returns the text up to and including the newline, and keeps the rest in a `static` buffer for the next call.
- **Bonus:** handles up to 1024 open files at once by keeping a separate leftover buffer for each one, so reads from different files can be interleaved.

## Skills demonstrated

- **Streaming / buffered I/O:** processing data in small chunks without loading the whole file into memory. It's the same principle behind reading large CSVs or logs in chunks (pandas `chunksize`, Python file iterators, data pipelines).
- **State between calls:** a `static` variable remembers where the previous call stopped, much like a Python generator or iterator.
- **Manual memory management:** every buffer is allocated and freed by hand, including on error paths.
- **Edge cases:** a last line with no newline, empty files, read errors, invalid file descriptors, and buffer sizes from 1 byte to very large.
- **Low-level understanding:** shows what a high-level `readline()` does under the hood.

## Usage

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```
##My result
<img width="888" height="222" alt="image" src="https://github.com/user-attachments/assets/29b23015-a0f2-4127-bfa7-8aec93a5cff0" />
