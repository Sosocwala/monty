#include "monty.h"

/**
 * monty_push - pushes a new element to a doubly linked list stack.
 *
 * @stack: the head of the stack(the base)
 * @line_num: current line number
 *
 *   bytecode.mode is a global variable:
 *       if set to 1, then the data is in stack mode
 *       if set to 0, then the data is in queue mode
 *
 *   stack mode is the default mode.
 */

void monty_push(stack_t **stack, unsigned int line_num)
{
	stack_t *head, *new;

	head = *stack;

	if (is_number(bytecode.arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (bytecode.mode == 0)
	{
		addqueue(stack);
		return;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bytecode.file);
		free(bytecode.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* adjust position of new element in the stack */
	new->n = atoi(bytecode.arg);
	new->next = NULL;
	new->prev = head;

	if (head != NULL)
		head->next = new;

	/* POSITION STACK POINTER to point to the top of stack */
	*stack = new;
}

/**
 * monty_pall - prints all the elements of the doubly linked stack
 * from the top.
 *
 * @stack: points to the top of the stack
 * @line_num: current line number
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
 * @stack: points to the top of the stack
 * @line_num: current line number
 */

void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *top2nd;
	int temp;

	top = *stack;

	/* check if the stack has at least two elements */
	if (top == NULL || top->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top2nd = top->prev;

	/* swap element values */
	temp = top->n;
	top->n = top2nd->n;
	top2nd->n = temp;
}

/**
 * monty_nop - does nothing
 *
 * @stack: points to the top of the stack
 * @line_num: current line number
 */

void monty_nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
