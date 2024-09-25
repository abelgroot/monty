#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the opcode appears (unused).
 *
 * Return: Nothing.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	last = *stack;

	/* Find the last node */
	while (last->next != NULL)
		last = last->next;

	/* Rotate the stack */
	*stack = top->next;
	(*stack)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}
