#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
	int *collection;
	int capacity;
	int size;
} Stack;

Stack *create_stack(int capcity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);


int main(void)
{
	int pop_val = 0, i;
	int peek_val = 0;
	Stack *stack = create_stack(5);

	if (stack == NULL)
	{
		printf("Error creating stack.\n");
		return (1);
	}
	
	if (is_empty(stack))
		printf("Stack is empty\n");

	push(stack, 2);
	push(stack, 9);
	printf("Stack size: %d\n", stack->size);
	push(stack, 4);
	push(stack, 7);
	push(stack, 8);
        printf("Stack size: %d\n", stack->size);

	if (is_full(stack))
		printf("Stack is full.\n");
	printf("Stack size: %d\n", stack->size);

	bool try_push = push(stack, 5);

	if (try_push == false)
		printf("Push failed.\n");
	else
		printf("Succesfull.\n");

	peek(stack, &peek_val);
	printf("Peek Val: %d\n", peek_val);

	for (i = 0; i < 5; i++)
	{
		pop(stack, &pop_val);
		printf("Popped value: %d\n", pop_val);
	}

	bool try_pop = pop(stack, &pop_val);
	if (try_pop == false)
		printf("Pop Failed.\n");
	bool try_peek = peek(stack, &peek_val);
	if (try_peek == false)
		printf("Peek Failed.\n");
	destroy_stack(stack);

	return (0);
}

bool pop(Stack *stack, int *item)
{
	if (is_empty(stack))
		return (false);
	stack->size--;
	*item = stack->collection[stack->size];
	return (true);
}

bool peek(Stack *stack, int *item)
{
	if (is_empty(stack) == true)
		return (false);

	*item = stack->collection[stack->size - 1];

	return (true);
}

Stack *create_stack(int capacity)
{
	if (capacity <= 0)
		return (NULL);
	Stack *stack = malloc(sizeof(Stack));
	
	if (stack == NULL)
		return (NULL);

	stack->collection = malloc(sizeof(int) * capacity);
	if (stack->collection == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;

	return (stack);
}

void destroy_stack(Stack *stack)
{
	free(stack->collection);
	free(stack);
}

bool is_full(Stack *stack)
{
	return (stack->capacity == stack->size);
}

bool is_empty(Stack *stack)
{
	return (stack->size == 0);
}

bool push(Stack *stack, int item)
{
	if (is_full(stack))
		return (false);
	
	stack->collection[stack->size] = item;
	stack->size++;

	return (true);
}

