#include "monty.h"

/**
 * execute - Executes the given opcode.
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
        {NULL, NULL}
    };
    
    int i = 0;
    while (instructions[i].opcode != NULL)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * run_monty - Executes the bytecode from a file.
 * @file: Pointer to the bytecode file.
 */
void run_monty(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		execute(opcode, &stack, line_number);
	}

	free(line);
	free_stack(stack);
}
