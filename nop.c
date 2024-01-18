#include "monty.h"
/**
 * nop - Implements the nop opcode
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty byte code file
 *
 * Return: Void.
 */
void nop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	(void)stack;
}
