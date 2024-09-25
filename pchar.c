#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack,
 * followed by a new line.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the opcode appears.
 *
 * Return: Nothing. Exits with EXIT_FAILURE on error.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Get the integer value at the top of the stack */
	value = (*stack)->n;

	/* Check if the value is a valid ASCII character */
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the corresponding ASCII character */
	printf("%c\n", value);
}
