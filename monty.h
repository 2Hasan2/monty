// monty.h

#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#define bufferSize 1024

/* Data structures */
/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Function pointer and corresponding operation string
 * @opcode: The operation string
 * @f: The function to perform the operation
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack);
} instruction_t;

/* Global variables */
extern int currentLine;

/* Function prototypes */
void handleExit(void **stack, int status);
void getLineNumber(size_t line_number);
void freeDlistint(stack_t *head);

/* Operation functions */
void pushOp(stack_t **stack);
void pallOp(stack_t **stack);
void pintOp(stack_t **stack);
void popOp(stack_t **stack);
void addOp(stack_t **stack);
void subOp(stack_t **stack);
void multiOp(stack_t **stack);
void divOp(stack_t **stack);
void pcharOp(stack_t **stack);
void pstrOp(stack_t **stack);
void rotlOp(stack_t **stack);
void rotrOp(stack_t **stack);

#endif /* MONTY_H */
