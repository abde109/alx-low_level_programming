#include "main.h"
#include <stdlib.h>

/**
 * wordcount - Counts the number of words in a string
 * @str: The string to count
 *
 * Return: The number of words in the string
 */
int wordcount(char *str)
{
	int count = 0;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
	char **words, *word;
	int i, j, k, wc;

	if (str == NULL || *str == '\0')
		return (NULL);

	wc = wordcount(str);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, k = 0; i < wc; i++)
	{
		while (str[k] == ' ')
			k++;
		j = k;
		while (str[j] && str[j] != ' ')
			j++;

		word = malloc((j - k + 1) * sizeof(char));
		if (word == NULL)
		{
			while (--i >= 0)
				free(words[i]);
			free(words);
			return (NULL);
		}
		words[i] = word;

		while (str[k] && str[k] != ' ')
			*word++ = str[k++];
		*word = '\0';
	}
	words[wc] = NULL;
	return (words);
}

