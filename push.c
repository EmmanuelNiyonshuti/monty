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

	token = strtok(NULL, " \t\n$");

	if (!token || !is_integer(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);

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
/**
 * is_integer - Checks if a string represents a valid integer
 * @str: The string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (!str || *str == '\0' || ((*str == '-' || *str == '+') && *(str + 1) == '\0'))
		return (0);
	while (*str)
	{
		if (!isdigit(*str) && !(*str == '-' && isdigit(*(str + 1))))
			return (0);
		str++;
	}
	return (1);
}
