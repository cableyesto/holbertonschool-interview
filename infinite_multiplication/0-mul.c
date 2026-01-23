#include <stdlib.h>

/* Function prototypes */
int _putchar(char c);
int is_digit(char *s);
int _strlen(char *s);
void errors(void);
void multiply(char *num1, char *num2);

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if true, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	if (!s)
		return (0);

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * errors - prints Error and exits with status 98
 */
void errors(void)
{
	int i;
	char msg[] = "Error\n";

	for (i = 0; msg[i]; i++)
		_putchar(msg[i]);
	exit(98);
}

/**
 * multiply - multiplies two numbers and prints the result
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len, i, j, carry, n1, n2;
	int *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (!result)
		exit(98);

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		_putchar('0');

	for (; i < len; i++)
		_putchar(result[i] + '0');
	_putchar('\n');

	free(result);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();

	multiply(argv[1], argv[2]);
	return (0);
}
