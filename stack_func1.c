#include "monty.h"

/**
 * monty_push - pushes a new element to a doubly linked list stack.
 * @stack: the head of the stack(the base)
 * @line_num: the line number of the program
 *
 */

void monty_push(stack_t **stack, unsigned int line_num)
{
	stack_t *head, *new;

	head = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}
	if (is_number(bytecode.arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}

	/* adjust position of new element in the stack */
	new->n = atoi(bytecode.arg);
	new->next = NULL;
	new->prev = head;

	if (head != NULL)
		head->next = new;

	/* POSITION STACK POINTER to pointer to the top of stack */
	*stack = new;
}

/**
 * monty_pall - prints all the elements of the doubly linked stack
 * from the top.
 *
 * @stack: points to top of the stack
 * @line_num: the line number of the program
 *
 */

void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tail;
	(void) line_num;

	tail = *stack;

	while (tail != NULL)
	{
		printf("%d\n", tail->n);
		tail = tail->prev;
	}
}

/**
 * monty_swap - swaps the top two elements of the stack
 *
 * @stack: points to top of the stack
 * @line_num: the current line number
 */

void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tail, *top1st, *top2nd;

	tail = *stack;

	/* check if the stack has at least two elements */
	if (tail == NULL || tail->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}

	/* identify top two positions in stack*/
	top1st = tail;
	top2nd = tail->prev;

	/* swap positions */
	top1st->prev = top2nd->prev;
	top2nd->next = top1st->next;

	top1st->next = top2nd;
	top2nd->prev = top1st;

	*stack = top2nd;
}

/**
 * monty_nop - does nothing
 *
 * @stack: base of the stack
 * @line_num: current line_ number
 */

void monty_nop(__attribute__((unused)) stack_t **stack, unsigned int line_num)
{
	(void) line_num;
}
