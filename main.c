#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	handleExit((void *)&stack, 1);

	char line[bufferSize];
	char *cmd;
	size_t numLine = 0;

	while (fgets(line, sizeof(line), fp) && ++numLine)
	{
		if ((cmd = strtok(line, " \t\n")) && cmd[0] != '#')
			runMonty(&stack, cmd);
	}

	fclose(fp);
	freeDlistint(stack);

	return 0;
}

/**
 * runMonty - Executes a Monty bytecode command.
 * @stack: A pointer to the pointer to the head of the stack.
 * @cmd: The Monty bytecode command to be executed.
 */
void runMonty(stack_t **stack, char *cmd)
{
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub}, {"div", div}, {"mul", multi},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", stackMode}, {"queue", queueMode}, {NULL, NULL}
	};

	for (int i = 0; instructions[i].opcode; i++)
	{
		if (!strcmp(cmd, instructions[i].opcode))
		{
			instructions[i].f(stack);
			return;
		}
	}

	fprintf(stderr, "L%zu: unknown instruction %s\n", numLine, cmd);
	_exit(EXIT_FAILURE);
}

/**
 * currentMode - Gets or sets the current mode.
 * @number: The new mode value to set (if non-negative).
 *
 * Return: The current mode.
 */
int currentMode(int number)
{
	static int mode;

	if (number >= 0)
		mode = number;

	return mode;
}
