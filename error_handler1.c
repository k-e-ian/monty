#include "monty.h"

/**
 * pop_error - print error message for pop
 * @line_number: error line_number
 * Return: EXITFAILURE
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: empty stack, cant pop!\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - pint error messages
 * @line_number: line number with error
 * Return: EXITFAILURE
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: empty stack, cant pint!\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * f_open_error - print file opening error
 * @filename: malloc error handler
 * Return: EXIT_FAILURE
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "error: cant open file %s, failed\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - print unkown instructions error messages
 * @opcode: operating code where error
 * @line_number: error line_number
 * Return: EXIT_FAILURE
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u:unknown command %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - invalid ints
 * @line_number: Line number with error
 * Return: EXITFAILURE
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push int only\n", line_number);
	return (EXIT_FAILURE);
}
