#include "monty.h"
/**
 * monty_pop - prints the top
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
/* removes the top element of the stack.*/
void monty_pop(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	/* If the stack is empty, print an error message and exit the program */
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
	        exit(EXIT_FAILURE);
	}
	/* Save, update, and free the top element of the stack. */
	h = *head;
	*head = h->prev;
	free(h);
}
