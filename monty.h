#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\b\t\b"

extern char **tok_op;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* string tokenizing functions */

char **strtow(char *str, char *deli);

int is_delim(char ch, char *deli);

int word_length(char *str, char *deli);

int word_count(char *str, char *deli);

char *next_word(char *str, char *deli);

/*stack_functions*/

void free_stack(stack_t **stack);

int init_stack(stack_t **stack);

int check_mode(stack_t *stack);

void free_tokens(void);

unsigned int arr_size(void);

int monty(FILE *script_fd);

void op_error(int error_code);

/*error_handling*/

int usage_error(void);

int malloc_error(void);

int f_open_error(char *filename);

int unknown_op_error(char *opcode, unsigned int line_number);

int no_int_error(unsigned int line_number);

int pop_error(unsigned int line_number);

int pint_error(unsigned int line_number);

int short_stack_error(unsigned int line_number, char *op);

int div_error(unsigned int line_number);

int pchar_error(unsigned int line_number, char *message);

/*tasks_prototypes*/

void _push(stack_t **stack, unsigned int line_number);

void _pall(stack_t **stack, unsigned int line_number);

void _pint(stack_t **stack, unsigned int line_number);

void _pop(stack_t **stack, unsigned int line_number);

void _swap(stack_t **stack, unsigned int line_number);

void monty_add(stack_t **stack, unsigned int line_number);

void monty_nop(stack_t **stack, unsigned int line_number);

void monty_sub(stack_t **stack, unsigned int line_number);

void monty_div(stack_t **stack, unsigned int line_number);

void monty_mul(stack_t **stack, unsigned int line_number);

void monty_mod(stack_t **stack, unsigned int line_number);

void monty_pchar(stack_t **stack, unsigned int line_number);

void monty_pstr(stack_t **stack, unsigned int line_number);

void monty_rotl(stack_t **stack, unsigned int line_number);

void monty_rotr(stack_t **stack, unsigned int line_number);

void queue_stack(stack_t **stack, unsigned int line_number);

void stack_queue(stack_t **stack, unsigned int line_number);

/*helper_functions*/
char **strtow(char *str, char *delims);

char *get_int(int n);

void free_tokens(void);

unsigned int token_arr_len(void);

int is_empty_line(char *line, char *delims);

void (*get_op_func(char *opcode))(stack_t**, unsigned int);

int run_monty(FILE *fd);

#endif
