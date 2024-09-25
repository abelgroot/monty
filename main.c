#include "monty.h"

/**
 * main - Monty bytecode interpreter entry point.
 * @argc: argument count.
 * @argv: argument vector, where argv[1] is the Monty bytecode file.
 *
 * Return: 0 on success, or EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];  /* Fixed buffer size for reading lines */
	char *opcode, *arg;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Reading the file line by line */
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \n");
		arg = strtok(NULL, " \n");

		if (opcode && strcmp(opcode, "push") == 0)
			push(&stack, line_number, arg);
		else if (opcode && strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
