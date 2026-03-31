# RegEx

## Requirements
### C

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called regex.h
- Don't forget to push your header file
- All your header files should be include guarded


## 0. Simple RegEx

Write a function that checks whether a given pattern matches a given string.

- Prototype: int regex_match(char const *str, char const *pattern);, where:
    - str is the string to scan
    - pattern is the regular expression
- Your function must return 1 if the pattern matches the string, or 0 if it doesn't
- str can be empty, and can contain any ASCII character in the exception of . and *
- pattern can be empty, and can contain any ASCII character, including . and *
- The regular expression matching must support the characters . and *
    - `.` matches any single character
    - `*` matches zero or more of the preceding character
