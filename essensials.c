#include "monty.h"

/**
 * _free - free pointer and set it to NULL
 * @ptr: pointer to free (void **)
 * Return: void
 * by Ashraf-Atef1 && AhMeDMaGDY28
 */
void _free(void **ptr)
{
	if (*ptr)
		free(*ptr), *ptr = NULL;
}

/**
 * _malloc - allocate memory and check if it failed
 * @size: size of memory to allocate (unsigned int)
 * Return: pointer to allocated memory (void *)
 * by Ashraf-Atef1 && AhMeDMaGDY28
 */
void *_malloc(unsigned int size)
{
	void *str = malloc(size);
	unsigned int i = 0;

	if (!str)
	{
		_Free(str);
		printf("Error: malloc failed\n"), _exit;
	}
	while (i < size)
		((char *)str)[i++] = '\0';
	return (str);
}

/**
 * _realloc - reallocate memory and check if it failed
 * @ptr: pointer to reallocate (void **)
 * @new_size: new size of memory to allocate (unsigned int)
 * Return: pointer to reallocated memory (void *)
 * by Ashraf-Atef1 && AhMeDMaGDY28
 */
void *_realloc(void *ptr, int new_size)
{
	void *temp;

	if (ptr && new_size < (int)strlen(ptr))
	{
		_Free(ptr);
		return (NULL);
	}
	temp = _malloc(new_size);
	memcpy(temp, ptr, ptr ? strlen(ptr) : 0);
	_Free(ptr);
	return (temp);
}
/**
 * get_line_number - Retrieves or sets the current line number.
 * @n: The new line number to be set (if >= 0).
 *
 * This function either retrieves the current line
 * number or sets it to a new value
 * if the provided value is non-negative.
 * It maintains the line number across calls
 * using a static variable.
 * If a non-negative value is passed, it updates the line number.
 *
 * Return: The current line number.
*
 */
int get_line_number(int n)
{
	static int line_number = -1;

	if (n >= 0)
		line_number = n;
	return (line_number);
}
/**
 * handle_exit - Handles cleanup and
 * exit operations based on the specified state.
 * @ptr: A pointer to the data needed for cleanup (stack or FILE pointer).
 * @state: The state indicating the type of cleanup or exit operation.
 *
 * This function handles different cleanup and
 * exit operations based on the specified state:
 * - State 1: Set the stack pointer.
 * - State 2: Set the FILE pointer.
 * - State 0: Perform cleanup operations,
 * such as freeing the stack and closing the FILE.
 *
 * Return: No return value.
*
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
		if (stack)
			free_listint(*stack);
		if (fp && *fp)
			fclose(*fp);
		exit(EXIT_FAILURE);
	}
}
