#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head node of list
 * @line_num: line number of bytecode file
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *fresh_node;
	int input;

	fresh_node = malloc(sizeof(size_t));
	if (!fresh_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!monty.arg || (_isdigit(monty.arg) == -1))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	input = atoi(monty.arg);
	fresh_node->n = input;
	fresh_node->next = NULL;
	fresh_node->prev = NULL;

	if (!(*stack))
	{
		(*stack) = fresh_node;
		return;
	}

	fresh_node->next = (*stack);
	(*stack)->prev = fresh_node;
	(*stack) = fresh_node;
}

/**
 * pall - prints all elements in a list
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints element at the top of a list
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (!(*stack)->next)
		*stack = NULL;
	else
		*stack = (*stack)->next, (*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to head node of list
 * @line_num: line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	if (temp->next)
	{
		(*stack)->next = temp->next;
		temp->next->prev = *stack;
	}
	else
		(*stack)->next = NULL;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
