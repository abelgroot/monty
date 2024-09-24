#include "monty.h"

/**
 * push - pushes an integer onto the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: current line number in the bytecode file.
 * @arg: the argument to be pushed, should be a valid integer.
 *
 * Description: The function pushes a value onto the stack.
 * If no valid integer is given, the function exits with an error.
 */
void push(stack_t **stack, unsigned int line_number)
{	
	stack_t *new_node = NULL;

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
 * pall - prints all values on the stack, starting from the top.
 * @stack: double pointer to the head of the stack.
 * @line_number: current line number in the bytecode file (unused).
 *
 * Description: The function traverses the stack from top to bottom
 * and prints all the values. If the stack is empty, nothing is printed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
