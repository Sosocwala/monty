#include "monty.h"
/**
  *monty_sub- sustration
  *@head: stack head
  *@line_num: line_number
  *Return: no return
 */
/* function that subtracts the top element of the stack from the second top element of the stack. */
void monty_sub(stack_t **head, unsigned int line_num)
{
	stack_t *aux;
	int sus, nodes;
	 /* Calculate the number of nodes in the stack */
	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	 /* If the stack has fewer than 2 elements, print an error message and exit the program */
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	/* Calculate the difference between the top two nodes and update the stack */
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
