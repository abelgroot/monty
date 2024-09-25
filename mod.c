#include "monty.h"
/**
* my_div - modulo the top two elements of the stack.
* @stack: Double pointer to the stack.
* @line_number: The line number in the bytecode file.
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second->n %= first->n; /* mod top two elements */
	pop(stack, line_number); /* Pop the top element */
}
