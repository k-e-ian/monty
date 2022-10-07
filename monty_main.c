#include "monty.h"

char **tok_op = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: array of char pointers to arguments
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on failure
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(fd);
	fclose(fd);
	return (exit_code);
}
