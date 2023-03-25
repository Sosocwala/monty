#include "monty.h"

/**
 * monty_queue - sets the format of the data
 * to a queue (FIFO).
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

void monty_queue(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;

	bytecode.mode = 0;
}


/**
 * addqueue - adds a new element to a doubly linked list queue,
 * possibly converted from a queue. New element is added
 * to the back of the queue.
 *
 * @queue: points to the front of the queue
 *
 * Description: When switching mode:
 *   The top of the stack becomes the front of the queue
 *   The front of the queue becomes the top of the stack
 *
 */
void addqueue(stack_t **queue)
{
	stack_t *front, *new;

	front = *queue; /* 'front' pointing to the front of queue */

	if (front)
		/* point to the back of the queue */
		while (front->prev != NULL)
			front = front->prev;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bytecode.file);
		free(bytecode.line);
		free_stack(queue);
		exit(EXIT_FAILURE);
	}

	/* front now points to the back of queue */
	front->prev = new;
	new->prev = NULL;
	new->n = atoi(bytecode.arg);
	new->next = front;
}
