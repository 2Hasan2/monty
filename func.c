#include "monty.h"

/**
 * push - opcode to push an element to the stack
 * @stack: double pointer to the beginning of the stack
 * @value: value to push onto the stack
 * @line_number: line number in the Monty byte code file
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	/* Implement the push opcode logic here */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - opcode to print all values on the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number in the Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	/* Implement the pall opcode logic here */
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/* Implement other opcode functions similarly */

/**
 * is_numeric - check if a string is a numeric value
 * @str: string to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * process_instruction - process Monty bytecode instruction
 * @opcode: opcode to process
 * @arg: arg for the opcode
 * @line_number: line number in the Monty byte code file
 */
void process_instruction(char *opcode, char *arg, unsigned int line_number)
{
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL || !is_numeric(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		value = atoi(arg);
		push(&stack, value, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(&stack, line_number);
	}
	/* Implement other opcode cases similarly */
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
