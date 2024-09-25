#include "monty.h"

/**
 * stack_mode - Sets the format to LIFO (stack).
 * @stack: Pointer to the stack (unused).
 * @line_number: Line number where the opcode appears (unused).
 *
 * Return: Nothing.
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 0; /* Set to LIFO */
}

/**
 * queue_mode - Sets the format to FIFO (queue).
 * @stack: Pointer to the stack (unused).
 * @line_number: Line number where the opcode appears (unused).
 *
 * Return: Nothing.
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 1; /* Set to FIFO */
}
