#include "monty.h"
/**
 * swap - Implements the swap opcode
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 *
 * Return: Void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next)
		temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
