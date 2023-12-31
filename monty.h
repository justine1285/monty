#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list represention of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * Description: opcode and its function for stack, queues,
 * LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_s - global variable for monty interpreter
 * @line_num: line number of byte code file
 * @arg: opcode argument
 * @stack: stack
 */
typedef struct monty_s
{
	unsigned int line_num;
	char *arg;
	stack_t *stack;
} monty_t;

/* in monty.c */
FILE *check_args(int arc, char **arv);
int main(int arc, char **arv);
void (*get_ops(char *opcode))(stack_t **, unsigned int);
void init_monty(void);

/* in utility.c */
int _isdigit(char *str);

extern monty_t monty;
monty_t monty;

/* operations */
void push(stack_t **, unsigned int line_num);
void pall(stack_t **, unsigned int line_num);
void pint(stack_t **, unsigned int line_num);
void pop(stack_t **, unsigned int line_num);
void swap(stack_t **, unsigned int line_num);

#endif
