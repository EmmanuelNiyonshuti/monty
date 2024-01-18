#include "monty.h"
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *current;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		current = *stack;
		while (current->next)
			current = current->next;
		last = current;
		current = last->prev;
		current->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
