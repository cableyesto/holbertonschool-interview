#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - checks if a string matches a pattern
 * @str: the string to scan
 * @pattern: the regex pattern
 *
 * Return: 1 if match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
