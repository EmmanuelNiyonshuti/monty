#include "monty.h"
/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *current;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		*stack = first->next;
		first->next = NULL;
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = first;
		first->prev = current;
	}
}
