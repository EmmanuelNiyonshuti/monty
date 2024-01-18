#include "monty.h"
/**
 * mod_op - Computes the Remainder of the Division of two numbers
 * @a: Dividend
 * @b: Divisor
 *
 * Return: Remainder of the division
 */
int mod_op(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "Error: division by zero\n");
		exit(EXIT_FAILURE);
	}
	return (a % b);
}
/**
 * mod - Implements the mod opcode
 * @stack: A pointer tothe top of the stack.
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Nothing.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = mod_op((*stack)->next->n, (*stack)->n);
	pop(stack, line_number);
}
