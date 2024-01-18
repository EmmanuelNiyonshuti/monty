#include "monty.h"
/**
 *div_op - Divides the second top element of the stack by the top element
 * @a: Second top element of the stack
 * @b: Top element of the stack
 *
 * Return: Result of the division
 */
int div_op(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "Error: division by zero\n");
		exit(EXIT_FAILURE);
	}
	return (a / b);
}
/**
*div_stack - Implements the div opcode
*@stack : A pointer to the top of the stack
*@line_number: The line number in the Monty byte code file
*
*Return: Void.
*/
void div_stack(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = div_op((*stack)->next->n, (*stack)->n);
	pop(stack, line_number);
}
