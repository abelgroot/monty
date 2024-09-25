#include "monty.h"

/**
 * pall - prints all values on the stack, starting from the top.
 * @stack: double pointer to the head of the stack.
 * @line_number: current line number in the bytecode file (unused).
 *
 * Description: The function traverses the stack from top to bottom
 * and prints all the values. If the stack is empty, nothing is printed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
