#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: The stack
 * @data: The data to be pushed
 * Return: Nothing
 */
void push(stack_t **stack, int data) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = data;
    new_node->prev = NULL;
    if (*stack == NULL) {
        new_node->next = NULL;
    } else {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: The stack
 * Return: Nothing
 */
void pall(stack_t **stack) {
    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: The stack
 * Return: Nothing
 */
void pint(stack_t **stack) {
    if (*stack == NULL) {
        fprintf(stderr, "Error: stack empty\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: The stack
 * Return: Nothing
 */
void pop(stack_t **stack) {
    if (*stack == NULL) {
        fprintf(stderr, "Error: stack empty\n");
        exit(EXIT_FAILURE);
    }
    stack_t *temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }
    free(temp);
}
