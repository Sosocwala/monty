#include "monty.h"
/**
 * monty_add - adds the top two elements of the stack.
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/

/* This function adds the top two elements of a stack*/
void monty_add(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;
	
	h = *head;
	/*Count the number of elements in the stack*/
	while (h)
	{
		h = h->next;
		len++;
	}
	/* If the stack has less than 2 elements, print an error message and exit*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	/*performing a stack addition operation, updates the stack values, and frees the old head of the stack*/
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
