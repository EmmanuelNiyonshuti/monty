#include "monty.h"
/**
 * add - Implements the add opcode
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n += (*stack)->n;
	pop(stack, line_number);
}
