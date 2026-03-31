# Substring with concatenated words

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
- The prototypes of all your functions should be included in your header file called substring.h
- Don't forget to push your header file
- All your header files should be include guarded

## 0. Substring with concatenated words

Write a function that finds all the possible substrings containing a list of words, within a given string.

- Prototype: `int *find_substring(char const *s, char const **words, int nb_words, int *n);`, where
- s is the string to scan
- words is the array of words all substrings must be a concatenation arrangement of
- nb_words is the number of elements in the array words
- n holds the address at which to store the number of elements in the returned array.
- Your function must return an allocated array, storing each index in s, at which a substring was found. If no solution is found, NULL can be returned
- All words in the array words are the same length
- A valid substring of s is the concatenation of each word in words exactly once and without any intervening characters
