#include "monty.h"

/**
 * free_tokens - Frees array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (tok_op == NULL)
		return;

	for (i = 0; tok_op[i]; i++)
		free(tok_op[i]);

	free(tok_op);
}

/**
 * token_arr_len - Gets the length of array
 * Return: Length of current array
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (tok_op[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line attributes
 * @line: pointer to the line.
 * @delims: delimiter characters.
 * Return: If the line only contains delimiters - 1, Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its specified function.
 * @opcode: The opcode to match.
 * Return: A pointer to specific function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", queue_stack},
		{"queue", stack_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}
