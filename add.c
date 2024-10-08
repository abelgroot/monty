#include "monty.h"
/**
* add - Adds the top two elements of the stack.
* @stack: Double pointer to the stack.
* @line_number: The line number in the bytecode file.
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n += first->n; /* Add top two elements */
	pop(stack, line_number); /* Pop the top element */
}
