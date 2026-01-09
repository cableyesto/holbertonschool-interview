# Heap Extract
## Requirements
### General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called binary_trees.h
- Don’t forget to push your header file
- All your header files should be include guarded

## 0. Heap - Extract

Write a function that extracts the root node of a Max Binary Heap:

- Prototype: int heap_extract(heap_t **root);
- root is a double pointer to the root node of the heap
- Your function must return the value stored in the root node
- The root node must be freed and replace with the last level-order node of the heap
- Once replaced, the heap must be rebuilt if necessary
- If your function fails, return 0
