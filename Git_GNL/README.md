*This project has been created as part of the 42 curriculum by archowdh.*

# get_next_line

Welcome to the implementation of `get_next_line`, read files line by line in C.

## Description

The goal of this project was to create a function that reads one line at a time from a file descriptor, returning it as a string each time the function is called. Key features include:

- Reading files efficiently using a buffer of size `BUFFER_SIZE`.
- Returning lines including the newline character (`\n`).
- Handling multiple file descriptors at once (bonus part).
- Managing memory dynamically to prevent leaks and errors.

> **Note:** The bonus part supports simultaneous reading from multiple file descriptors without mixing data.

---

## Project Structure
```
get_next_line/
├── get_next_line.c                # Main function logic
├── get_next_line_utils.c          # Helper functions for strings and memory
├── get_next_line_bonus.c          # Bonus version supporting multiple FDs
├── get_next_line_utils_bonus.c    # Bonus helpers
├── get_next_line.h                # Header file with prototypes and macros
├── get_next_line_bonus.h          # Bonus header file with prototypes and macros

```
---

## Functions Implemented

### Core Function

- **get_next_line(int fd)**: Reads the next line from the given file descriptor and returns it as a malloc’ed string, or NULL when EOF or error occurs.

### Utility Functions (in get_next_line_utils.c)

- **ft_strchr**: Finds a character in a string.  
- **ft_strndup**: New string containing up to n characters copied from the 	original string.  
- **ft_strjoin**: Joins two strings into a new malloc’ed string. 
- **ft_strlen**: Calculates string length.

### Bonus Features

- Supports multiple file descriptors by keeping a separate buffer for each FD.

### Algorithm Overview

The `get_next_line` function reads from a file descriptor and returns one line at a time, using a static buffer (stash) to preserve unread data between calls.
1. Persistent Storage (stash)
	- A static array stash[fd] is used to store leftover data for each file descriptor, allowing multiple files to be read simultaneously without mixing content.
2. Reading from File (ft_read_file)
	- Data is read from the file using read() into a temporary buffer.
	- The buffer is appended to stash (stash[fd]) using ft_strjoin.
	- Reading continues until:
		- A newline (\n) is found, or End of file (EOF) is reached
3. Extracting the Line (ft_get_line)
	- The function identifies the first newline in stash.
	- It extracts and returns a substring up to and including \n (or the entire content if no newline exists).
4. Updating the Stash (ft_new_stash)
	- After extracting the line, the remaining part of stash (stash[fd]) (after the newline) is duplicated into a new string.
	- The old stash is freed to prevent memory leaks.
5. Returning the Result
	- The extracted line is returned to the caller.
	- Memory allocated for the line must be freed by the caller after use.

---
## Instructions

### 1. Clone the repository:
```bash
git clone <git link.git>
cd <inside the git repository>

```
### 2. To complie:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c (bonus)

```
### 3. main function:
```
#include "get_next_line.h"

# include <fcntl.h>
# include <stdio.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
```
BONUS
```
#include "get_next_line_bonus.h"

# include <fcntl.h>
# include <stdio.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line;
	int fd1 = open("file1.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\n---------------------------------------\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	close(fd1);
}

```
---

## Resources

The **get_next_line** project focuses on implementing a function that reads and returns a line from a file descriptor, making official documentation like the Linux man-pages an essential reference—especially for understanding system calls such as `read`, file descriptors, and buffer behavior. Resources like GeeksforGeeks ([https://www.geeksforgeeks.org/c/c-programming-language/](https://www.geeksforgeeks.org/c/c-programming-language/)) and TutorialsPoint ([https://www.tutorialspoint.com/cprogramming/index.htm](https://www.tutorialspoint.com/cprogramming/index.htm)) offer clear explanations of file I/O in C, memory management, static variables, and string manipulation, all of which are fundamental for this project.

To ensure robustness and correctness, AI was used to explore a variety of edge cases, including handling different buffer sizes, reading from multiple file descriptors, managing memory leaks, dealing with end-of-file conditions, handling empty files, and ensuring correct behavior with and without newline characters.


## Author

**Arunima Chowdhury**

Codam Amsterdam