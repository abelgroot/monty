#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the opcode appears (unused).
 *
 * Return: Nothing.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	/* Find the last and second last elements */
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	/* Rotate the stack */
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
