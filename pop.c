#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the pointer to the head of the stack.
 * Return: No return value.
 */

void pop(stack_t **stack)
{
	stack_t *temp;

	if (!*stack)
		fprintf(stderr, "L%d: can't pop an empty stack\n", c_Line), _exit;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
