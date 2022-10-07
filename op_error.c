#include "monty.h"

/**
 * op_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void op_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL, **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!tok_op)
	{
		malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = tok_op[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(tok_op);
	tok_op = new_toks;
}
