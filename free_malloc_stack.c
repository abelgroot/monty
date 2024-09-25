#include "monty.h"

/**
 * free_stack - Frees the stack.
 * @stack: Pointer to the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * safe_malloc - Wrapper for malloc to check for allocation failure.
 * @size: The size to allocate.
 *
 * Return: Pointer to allocated memory.
 */
void *safe_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
