#include "monty.h"
/**
 * monty_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
/*prints the char at the top of the stack, followed by a new line.*/
void monty_pchar(stack_t **head, unsigned int line_num)
{
	stack_t *h; /* declare a pointer to a stack_t struct */

	h = *head; /* set h to point to the first node in the stack */
	/*check if the stack is empty */
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	/*  check if the value in the top node is within the ASCII range */
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	/* print the character associated with the value in the top node */
	printf("%c\n", h->n);
}
