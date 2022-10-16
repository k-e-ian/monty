#include "monty.h"

/**
 * short_stack_error - print math function error messages (2 node)
 * @line_number: error location
 * @op: operation error
 * Return: EXIT_FAILURE
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - error of 0 division
 * @line_number: line number error
 * Return: EXITFAILURE
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pchar_error - prints pchar errs
 * @line_number: error line
 * @message: err mess
 * Return: EXITFAILURE
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

/**
 * usage_error - error handler
 * Return: EXIT_FAILURE
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - malloc error handler
 * Return: EXIT_FAILURE
 */
int malloc_error(void)
{
	fprintf(stderr, "ERROR: m-alloc failed\n");
	return (EXIT_FAILURE);
}
