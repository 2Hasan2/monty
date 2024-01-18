#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the pointer to the head of the stack.
 * Return: No return value.
 */
void pint(stack_t **stack)
{
	if (!*stack)
		fprintf(stderr, "L%d: can't pint, stack empty\n", c_Line), _exit;
	printf("%d\n", (*stack)->n);
}
