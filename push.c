#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the pointer to the head of the stack.
 * Return: No return value.
 */
void push(stack_t **stack)
{
	char *n = strtok(NULL, " \t\n");
	int i = 0;

	if (!n || !*n)
		fprintf(stderr, "L%d: usage: push integer\n", c_Line), _exit;
	if (n[i] == '-')
		i++;
	while (n[i])
		if (n[i] < '0' || n[i++] > '9')
			fprintf(stderr, "L%d: usage: push integer\n", c_Line), _exit;
	if (_mod == 0)
		add_node_int(stack, atoi(n));
	else
		add_node_int_end(stack, atoi(n));
}
