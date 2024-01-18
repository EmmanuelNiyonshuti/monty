#include "monty.h"
/**
 * mul - Implements the mul opcode
 * @stack: A pointer to the top of the stack
 * @line_number: the line number of the Monty byte code file
 *
 * Return: Nothing.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
