#include "monty.h"

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/**
 * _pall - Prints the elements of stack_t
 * @stack: pointer to pointer to stack
 * @line_number: monty line_number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;
	
	if (stack == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}

/**
 * _pint - prints the top of stack_t
 * @stack: pointer to pointer to top node
 * @line_number: current line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL && stack == NULL)
	{
		op_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * _pop - removes the top value
 * @stack: pointer to pointer to top node
 * @line_number: cureent working line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		op_error(pop_error(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * _swap - swap top two value elements of stack_t
 * @stack: A pointer to pointer to top node
 * @line_number: The current working line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_error(short_stack_error(line_number, "swap"));
		return;
	}

	if (stack == NULL)
		return;

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;

	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}

/**
 * _push - inserts value top of stack_t
 * @stack: pointer to pointer to top
 * @line_number: current working line
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		op_error(malloc_error());
		return;
	}
	if (tok_op[1] == NULL)
	{
		op_error(no_int_error(line_number));
		return;
	}

	for (i = 0; tok_op[1][i]; i++)
	{
		if (tok_op[1][i] == '-' && i == 0)
			continue;
		if (tok_op[1][i] < '0' || tok_op[1][i] > '9')
		{
			op_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(tok_op[1]);
/*	FILO*/
	if (check_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new->prev = *stack;
		new->next = temp;
		if (temp)
			temp->prev = new;
		(*stack)->next = new;
	}
	else/*LILO*/
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
	}
}
