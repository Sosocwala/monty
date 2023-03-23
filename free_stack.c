#include "monty.h"

/**
 * free_stack - frees the memory of a doubly linked
 * list stack
 *
 * @stack: the top of the stack
 *
 */

void free_stack(stack_t **stack)
{
	stack_t *tail;

	tail = *stack;

	while (tail != NULL)
	{
		*stack = tail->prev;
		free(tail);
		tail = *stack;
	}
}
