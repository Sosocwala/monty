#include "monty.h"
/**
  *monty_rotr- rotates the stack to the bottom
  *@head: stack head
  *@line_num: line_number
  *Return: no return
 */
/* function that rotates the stack to the bottom */
void monty_rotr(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	stack_t *copy;
	/* Save a copy of the head pointer */
	copy = *head;

	/* If the stack is empty or has only one element, return without doing anything */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	/* Traverse to the last element of the stack */
	while (copy->next)
	{
		copy = copy->next;
	}
	 /*  Rotate the stack by moving the last element to the top */
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
