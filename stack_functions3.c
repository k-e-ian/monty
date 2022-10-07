#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void queue_stack(stack_t **stack, unsigned int line_number);
void stack_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotates top value of a stack_t linked list to the bottom.
 * @stack: A pointer to pointer to node of a stack_t
 * @line_number: The current working line
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - Rotates bottom value of a stack_t linked list to the top.
 * @stack: A pointer to pointer to node of a stack_t linked list.
 * @line_number: The current working line number
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * queue_stack - Converts a queue to a stack.
 * @stack: A pointer to pointer to top of stack_t linked list.
 * @line_number: The current working line number
 */
void queue_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * stack_queue - Converts a stack to a queue.
 * @stack: A pointer to pointer to stack_t linked list.
 * @line_number: The current working line
 */
void stack_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
