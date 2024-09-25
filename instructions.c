#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number in the bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	char *arg = strtok(NULL, " \t\n");
	if (arg == NULL || (!isdigit(arg[0]) && arg[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = safe_malloc(sizeof(stack_t));
	new_node->n = atoi(arg);
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
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

/**
 * pint - Prints the top value of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number in the bytecode file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
