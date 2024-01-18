#include "monty.h"

/**
 * p_listint - print a doubly linked list
 * @h: the head node pointer
 * Return: the size of the list
 */
size_t p_listint(const stack_t *h)
{
	size_t size = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		size++;
	}
	return (size);
}

/**
 * add_node_int - add a new node to the linked list at the beginning
 * @head: the head node pointer
 * @n: the value of the new node
 * Return: a pointer the new node
 */
stack_t *add_node_int(stack_t **head, const int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
		return (NULL);
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	if (*head)
		(*head)->prev = newNode;
	*head = newNode;
	return (newNode);
}

/**
 * add_node_int_end - add a new node to the linked list at the end
 * @head: the head node pointer
 * @n: the value of the new node
 * Return: a pointer the new node
 */
stack_t *add_node_int_end(stack_t **head, const int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	stack_t *h = *head;

	if (!newNode)
		return (NULL);
	newNode->n = n;
	newNode->next = NULL;
	if (!*head)
	{
		newNode->prev = NULL;
		*head = newNode;
		return (newNode);
	}
	while (h->next)
		h = h->next;
	h->next = newNode;
	newNode->prev = h;
	return (newNode);
}

/**
 * free_listint - free a doubly linked list
 * @head: the head node pointer
 */
void free_listint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
