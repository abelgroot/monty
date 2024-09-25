#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number in the bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	stack_t *new_node, *last;

	if (arg == NULL || (!isdigit(arg[0]) && arg[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	if (mode == 0) /* LIFO mode */
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	else if (mode == 1) /* FIFO mode */
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number in the bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* unused variable */
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
