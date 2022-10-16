#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Does nothing
 * @stack: A pointer to pointer to first node of a stack_t
 * @line_number: The current line
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Prints the char at top
 * @stack: A pointer to a pointer to top node of a stack_t
 * @line_number: The current line
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		op_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		op_error(pchar_error(line_number, "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string in a stack_t
 * @stack: A pointer to to pointer to node of a stack_t
 * @line_number: The current working line
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;
	
	if (stack == NULL)
		return;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)line_number;
}
