#include "monty.h"
/**
 * monty_pint - prints the top
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
/* function that prints the value at the top of the stack, followed by a new line.*/
void monty_pint(stack_t **head, unsigned int line_num)
{
	/* Check if the stack is empty */
	if (*head == NULL)
	{
		/* If the stack is empty, print an error message */
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	/* Prints the integer value of the n member of the node that head is pointing to, followed by a newline character */
	printf("%d\n", (*head)->n);
}
