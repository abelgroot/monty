#include "monty.h"

/**
 * pstr - Prints the string starting from the top of the stack,
 * followed by a new line.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the opcode appears.
 *
 * Return: Nothing. Exits with EXIT_FAILURE on error.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /* Unused */
	int value;

	while (current != NULL)
	{
		value = current->n;

		/* Stop if the value is not a valid ASCII character or is 0 */
		if (value <= 0 || value > 127)
			break;

		/* Print the character */
		printf("%c", value);

		/* Move to the next node in the stack */
		current = current->next;
	}

	/* Print a new line at the end */
	printf("\n");
}
