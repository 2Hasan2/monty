#include "monty.h"
/**
 * main - Entry point.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 * Return: Always 0.
*/
int main(int argc, char const *argv[])
{
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	else
	{
		char line[buffer_size];
		size_t num_line = 0;
		char *command;
		FILE *fp = fopen(argv[1], "r");
		stack_t *stack = NULL;

		if (fp == NULL)
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

		handle_exit((void *)&stack, 1);
		while (fgets(line, sizeof(line), fp) != NULL)
		{
			get_line_number(++num_line);
			command = strtok(line, " \t\n");
			if (command && command[0] != '#')
				run_monty(&stack, command);
		}
		fclose(fp);
		free_listint(stack);
	}
	return (0);
}
/**
 * run_monty - Runs the monty program.
 * @stack: A pointer to the pointer to the head of the stack.
 * @command: The command to run.
 * Return: No return value.
*/
void run_monty(stack_t **stack, char *command)
{
	int i, idx = 0;
	instruction_t instructions[] = {{"push", push},
							  {"pall", pall},
							  {NULL, NULL}};

	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(command, instructions[i].opcode) == 0)
			idx = 1, instructions[i].f(stack);
	if (idx == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n", c_Line, command), _exit;
}
/**
 * current_mode - Sets the current mode of the program.
 * @number: The mode to set.
 * Return: The current mode.
*/
int current_mode(int number)
{
	static int mode;

	if (number >= 0)
		mode = number;
	return (mode);
}
