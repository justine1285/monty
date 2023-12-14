#include "monty.h"

/**
 * init_monty - initialize global variables
 */
void init_monty(void)
{
	monty.arg = NULL;
	monty.line_num = 0;
	monty.stack = NULL;
}

/**
 * check_args - opens byte code file
 * @arc: argument count
 * @arv: argument vector
 * Return: file pointer to byte code
 */
FILE *check_args(int arc, char **arv)
{
	FILE *fp;

	if (arc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(arv[1], "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}

	return (fp);
}

/**
 * main - runs a bytecode
 * @arc: (int) argument count
 * @arv: (char **) argument vector
 * Return: 0 on success
 */
int main(int arc, char **arv)
{
	FILE *fp;
	char *lineptr = NULL, *opcode;
	const char DELIM[3] = " \t\n";
	size_t n = 0;
	ssize_t flag;
	void (*func)(stack_t **, unsigned int);

	fp = check_args(arc, arv);

	while ((flag = getline(&lineptr, &n, fp) != -1))
	{
		monty.line_num++;
		opcode = strtok(lineptr, DELIM);
		if (opcode)
		{
			func = get_ops(opcode);
			if (!func)
			{
				dprintf(2, "L%d: unknown instruction %s\n", monty.line_num, opcode);
				exit(EXIT_FAILURE);
			}
			monty.arg = strtok(NULL, DELIM);
			func(&monty.stack, monty.line_num);
		}
	}
	free(lineptr);
	fclose(fp);
	return (0);
}
