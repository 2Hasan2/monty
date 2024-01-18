#include "monty.h"

/**
 * _free - Frees a pointer.
 * @ptr: A pointer to the pointer to free.
 * Return: No return value.
 */
void _free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * _malloc - Allocates memory using malloc.
 * @size: The size of the memory to allocate.
 *
 * Return: A pointer to the allocated memory.
 */
void *_malloc(unsigned int size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
		fprintf(stderr, "Error: malloc failed\n"), _exit;
	return (ptr);
}


/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @new_size: The new size of the memory block.
 *
 * Return: A pointer to the reallocated memory.
 */

void *_realloc(void *ptr, int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			fprintf(stderr, "Error: malloc failed\n"), _exit;
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		fprintf(stderr, "Error: malloc failed\n"), _exit;
	memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
/**
 * get_line_number - Gets the line number.
 * @n: The new line number.
 *
 * Return: The line number.
*/
int get_line_number(int n)
{
	static int num_line;

	if (n >= 0)
		num_line = n;
	return (num_line);
}

/**
 * handle_exit - Handles the exit.
 * @ptr: A pointer to the stack.
 * @state: The state to set.
 *
 * Return: No return value.
 */
void handle_exit(void *ptr, int state)
{
	static FILE **fp;
	static stack_t **stack;

	if (state == 1)
		stack = (stack_t **)ptr;
	else if (state == 2)
		fp = (FILE **)ptr;
	else if (state == 0)
	{
		if (*stack)
			free_listint(*stack);
		if (*fp)
			fclose(*fp);
	}
}
