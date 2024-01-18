#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _Free(a) (_free((void *)&(a)))
#define c_Line (get_line_number(-1))
#define is_skip_line (get_next_line(-1))
#define _exit (handle_exit(NULL, 0))
#define _mod (current_mode(-1))
#define skip_line (get_next_line(1))
#define Buffer_Size 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack);
} instruction_t;


void *_malloc(unsigned int size);
int get_line_number(int n);
void *_realloc(void *ptr, int new_size);
void _free(void **ptr);
void handle_exit(void *ptr, int state);

stack_t *add_node_int(stack_t **head, const int n);
void free_listint(stack_t *head);
stack_t *add_node_int_end(stack_t **head, const int n);
size_t p_listint(const stack_t *h);
stack_t *get_node_index(stack_t *head, unsigned int index);
int current_mode(int number);
void run_monty(stack_t **stack, char *command);


void push(stack_t **stack);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop_op(stack_t **stack);
void swap_op(stack_t **stack);

/* ========== op_instructions_2.c ========== */

void add_op(stack_t **stack);
void nop_op(stack_t **stack);
void sub_op(stack_t **stack);
void div_op(stack_t **stack);
void multi_op(stack_t **stack);

/* ========== op_instructions_3.c ========== */

void mod_op(stack_t **stack);
void pchar_op(stack_t **stack);
void pstr_op(stack_t **stack);
void rotl_op(stack_t **stack);
void rotr_op(stack_t **stack);

/* ========== op_instructions_4.c ========== */

void stack_mode(stack_t **stack);
void queue_mode(stack_t **stack);
size_t dlistint_len(const stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);


#endif
