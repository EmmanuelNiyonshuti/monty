#include "monty.h"
/**
 * sub - Implements the sub opcode
 * @stack: A pointer to the top of the stack
 * @line_number: Th line number in the Monty byte code file
 *
 * Return: Void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "LU%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
