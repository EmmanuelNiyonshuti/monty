#define _GNU_SOURCE
#include "monty.h"
/**
 * main - Entry Point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *token;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		token = strtok(line, " \t\n");
		if (token)
			process_opcode(&stack, token, line_number);
	}
	free(line);
	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
/**
 * process_opcode - Process Monty opcode and execute corresponding function
 * @stack: A poineter to the top of the stack
 * @opcode: The opcode to process
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void.
 */
void process_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_stack},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	if (opcode[0] == '#')
	{
		comments(stack, line_number);
		return;
	}
	fprintf(stderr, "L%u: uknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - Frees the elements of the stack.
 * @stack: A pointer to the to top of the stack
 *
 * Return: Void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
