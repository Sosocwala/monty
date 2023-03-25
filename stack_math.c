#include "monty.h"

/**
 * monty_div - divides the second top element of the stack
 * by the top element of the stack
 *
 * @stack: points to the top of the stack
 * @line_num: current line number
 *
 */
void monty_div(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *top2nd;
	int result;

	top = *stack;

	/* check if the stack contains at least two elements */
	if (top == NULL || top->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/* check if top element is 0 */
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top2nd = top->prev;

	/* get division result */
	result = (top2nd->n) / (top->n);
	top2nd->n = result;
	top2nd->next = NULL;

	*stack = top2nd; /* new top element to point to */
	free(top);
}

/**
 * monty_mul - multiplies the second top element of the stack
 * with the top element of the stack
 *
 * @stack: points to the top of the stack
 * @line_num: current line number
 *
 */
void monty_mul(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *top2nd;
	int result;

	top = *stack;

	/* check if the stack contains at least two elements */
	if (top == NULL || top->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(bytecode.file);
		free(bytecode.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top2nd = top->prev;

	/* get multiplication result */
	result = (top2nd->n) * (top->n);
	top2nd->n = result;
	top2nd->next = NULL;

	*stack = top2nd; /* new top element to point to */
	free(top);
}
