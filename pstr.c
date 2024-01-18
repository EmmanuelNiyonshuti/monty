#include "monty.h"
/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
