#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the pointer to the head of the stack.
 * Return: No return value.
 */

void add(stack_t **stack)
{
	stack_t *temp;
	int n;

	if (!*stack || !(*stack)->next)
		fprintf(stderr, "L%d: can't add, stack too short\n", c_Line), _exit;
	temp = *stack;
	n = temp->n + temp->next->n;
	pop(stack);
	(*stack)->n = n;
}
