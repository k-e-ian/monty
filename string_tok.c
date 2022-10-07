#include <stdlib.h>
#include "monty.h"

/**
 * strtow - takes str seperates its toks
 * @str: string to seperate into words
 * @deli: delimitors
 * Return: array of pointers to each word
 */
char **strtow(char *str, char *deli)
{
	char **tok = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = word_count(str, deli);
	
	if (wc == 0)
		return (NULL);
	
	tok = malloc((wc + 1) * sizeof(char *));
	
	if (tok == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = word_length(str, deli);
		if (is_delim(*str, deli))
		{
			str = next_word(str, deli);
		}
		tok[i] = malloc((wordLen + 1) * sizeof(char));
		if (tok[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(tok[i]);
			}
			free(tok);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			tok[i][n] = *(str + n);
			n++;
		}
		tok[i][n] = '\0';
		str = next_word(str, deli);
		i++;
	}
	tok[i] = NULL;
	return (tok);
}

/**
 * is_delim - checks if stream has delimitor char
 * @ch: character
 * @deli: Pointer to delimitors
 * Return: 1 on success 0 on failure
 */
int is_delim(char ch, char *deli)
{
	int i = 0;

	while (deli[i])
	{
		if (deli[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * word_length - gets the word length in str
 * @str: string to get word length from current word
 * @deli: delimitors
 * Return: word length of current word
 */
int word_length(char *str, char *deli)
{
	int wLen = 0, next = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], deli))
			next = 1;
		else if (next)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], deli))
			break;
		i++;
	}
	return (wLen);
}

/**
 * word_count - gets the word count of a string
 * @str: string to get word count from
 * @deli: delimitors
 * Return: the word count of the string
 */
int word_count(char *str, char *deli)
{		/*word count*/
	int wc = 0, next = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], deli))
			next = 1;
		else if (next)
		{
			next = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * next_word - gets the next word in a string
 * @str: string to get next word from
 * @deli: delimitors
 * Return: pointer to first char of next word
 */
char *next_word(char *str, char *deli)
{
	int next = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], deli))
			next = 1;
		else if (next)
			break;
		i++;
	}
	return (str + i);
}
