#include "monty.h"

/**
 * run_monty - Executes the bytecode from a file.
 * @file: Pointer to the bytecode file.
 */
void run_monty(FILE *file)
{
	char line[2560]; /* Static buffer for line */
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		/* Skip empty lines or comments */
		if (opcode == NULL || opcode[0] == '#')
			continue;

		execute(opcode, &stack, line_number); /* Execute the opcode */
	}

	free_stack(stack); /* Free the entire stack before exiting */
}

/**
 * execute - Executes the opcode.
 * @opcode: The opcode to execute.
 * @stack: Double pointer to the stack.
 * @line_number: The line number in the bytecode file.
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
