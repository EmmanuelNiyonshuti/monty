#include "monty.h"
#include <ctype.h>
/**
 * push - Implements the push opcode
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file.
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;
	stack_t *new_node;

	token = strtok(NULL, " \t\n");
	if (!token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
	if (strspn(token, "0123456789-+") != strlen(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
