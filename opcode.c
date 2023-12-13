#include "monty.h"
/**
 * get_ops - gets the function of opcode
 * @opcode: opcode from bytecode file
 * Return: NULL if function is not found
 */
void (*get_ops(char *opcode))(stack_t **, unsigned int)
{
	int k = 0;

	instruction_t op_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL},
	};

	while (op_list[k].opcode)
	{
		if (strcmp(opcode, op_list[k].opcode) == 0)
			return (op_list[k].f);
		k++;
	}
	return (NULL);
}
