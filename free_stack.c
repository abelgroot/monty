#include "monty.h"

/**
 * free_stack - frees a doubly linked list (stack).
 * @stack: pointer to the head of the stack.
 *
 * Description: The function traverses the stack and frees each node.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
