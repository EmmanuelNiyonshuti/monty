#include "monty.h"
/**
 * pint - Implements the pint opcode
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the monty byte code file
 *
 * Return: Void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
