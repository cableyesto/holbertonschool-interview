#include <stdlib.h>
#include <string.h>

#include "substring.h"

/**
 * _strncmp - compares two strings up to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes
 *
 * Return: 0 if identical, non-zero otherwise
 */
static int _strncmp(char const *s1, char const *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * check_match - checks if substring starting at index is valid
 * @s: main string
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 * @index: starting index
 *
 * Return: 1 if valid, 0 otherwise
 */
static int check_match(char const *s, char const **words,
	int nb_words, int word_len, int index)
{
	int i;
	int j;
	int found;
	int *used;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
				_strncmp(s + index + i * word_len,
					words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}

	free(used);
	return (1);
}

/**
 * find_substring - finds all starting indices of valid substrings
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of words
 * @n: pointer to store number of results
 *
 * Return: array of indices or NULL
 */
int *find_substring(char const *s, char const **words,
	int nb_words, int *n)
{
	int i;
	int len_s;
	int word_len;
	int total_len;
	int count;
	int *result;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	len_s = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	result = malloc(sizeof(int) * len_s);
	if (!result)
		return (NULL);

	count = 0;
	for (i = 0; i <= len_s - total_len; i++)
	{
		if (check_match(s, words, nb_words, word_len, i))
		{
			result[count] = i;
			count++;
		}
	}

	if (count == 0)
	{
		free(result);
		return (NULL);
	}

	*n = count;
	return (result);
}
