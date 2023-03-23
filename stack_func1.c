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

	new->n = atoi(bytecode.arg);
	new->next = NULL;

	if (head == NULL)
	{
		new->prev = head;
		*stack = new;
	}
	else /* not an empty stack */
	{
		while (head->next != NULL) /* move to last stack element */
			head = head->next;

		head->next = new;

		new->prev = head;
	}
}

/**
 * monty_pall - prints all the elements of the doubly linked stack
 * from the top.
 *
 * @stack: the head of the stack
 * @line_num: the line number of the program
 *
 */

void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *head;
	(void) line_num;

	/* move head to the top of the stack */
	head = *stack;
	if (head != NULL)
	{
		while (head->next != NULL)
			head = head->next;
	}

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->prev;
	}
}

/**
 * monty_swap - swaps the top two elements of the stack
 *
 * @stack: the base of the stack
 * @line_num: the current line number
 */

void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *head, *top1st, *top2nd;

	head = *stack;

	/* check if the stack has at least two elements */
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		exit(EXIT_FAILURE);
	}

	/* get top two elements of stack */
	while (head != NULL)
	{
		if (head->next == NULL) /* top element */
			top1st = head;

		if (head->next->next == NULL) /* second top element */
			top2nd = head;

		head = head->next;
	}

	top1st->prev = top2nd->prev;
	top2nd->next = top1st->next;

	top1st->next = top2nd;
	top2nd->prev = top1st;
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
