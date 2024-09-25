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
    return ptr;
}
