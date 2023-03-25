#include "monty.h"
/**
 * monty_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
/*This function computes the rest of the division of the second top element of the stack by the top element of the stack.*/
void monty_mod(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;
	/*Count the number of elements in the stack*/
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	/* Check if there are at least two elements in the stack*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	/* Set 'h' to point to the head of the stack*/
	h = *head;
	/* Check if dividing by 0*/
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	/*Perform the modulo operation and update the stack values*/
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
