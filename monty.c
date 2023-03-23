#include "monty.h"

bytecode_t bytecode = {NULL, NULL, NULL, NULL};

/**
 * main - entry point for the monty program
 * @ac: program's argument number
 * @av: string arguments of program
 *
 * Return: EXIT_SUCCESS on successful run,
 * or EXIT_FAILURE on failure.
 */

int main(int ac, char *av[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r"); /* open monty file */
	bytecode.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	read_lines(&stack);
/*	free_dlistint();*/

	return (0);
}

