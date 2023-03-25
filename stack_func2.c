#include "monty.h"

/**
 * monty_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @stack: points to the top of the stack
 * @line_num: current line number
 *
 * Description: The string stops when either:
 *   the stack is over
 *   the value of the element is 0
 *   the value of the element is not in the ascii table
 */

void monty_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tail;
	int value;
	(void) line_num;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	tail = *stack; /* points to the top of the stack */

	while (tail != NULL)
	{
		value = tail->n;

		 /* value is within ascii table */
		if (value <= 0 || value > 127)
			break;

		putchar(value);
		tail = tail->prev;
	}
	putchar('\n');
}


/**
 * monty_rotl - rotates the stack to the top.
 *
 * @stack: points to the top of the stack
 * @line_num: current line number
 *
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 * 'rotl' never fails.
 *
 */
void monty_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *current, *top, *top2nd;
	(void) line_num;

	current = *stack;

	/* ensure that the stack has atleast two elements */
	if (current == NULL || current->prev == NULL)
		return;

	top = *stack;
	top2nd = top->prev;

	/* make current point to the bottom of the stack */
	while (current->prev != NULL)
		current = current->prev;

	top->prev = NULL;
	top->next = current;
	current->prev = top;
	top2nd->next = NULL;

	*stack = top2nd;
}


/**
 * monty_stack - sets the format of the data
 * to a stack (LIFO).
 *
 * @stack: points to the top of the stack
 * @line_num: current line number
 *
 * Description: When switching mode:
 *   The top of the stack becomes the front of the queue
 *   The front of the queue becomes the top of the stack
 *
 *   bytecode.mode is a global variable:
 *       if set to 1, then the data is in stack mode
 *       if set to 0, then the data is in queue mode
 *
 *   stack mode is the default mode.
 */

void monty_stack(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;

	bytecode.mode = 1;
}
