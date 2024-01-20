#include "monty.h"
/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
	}
}
/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (*stack)
	{
		while (current->next)
			current = current->next;
		*stack = current;
	}
}
