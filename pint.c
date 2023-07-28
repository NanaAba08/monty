#include "monty.h"

/**
* pint -prints  the value at the top of the stack (pint opcode).
* @stack: Pointer to the top of the stack.
* @line_number: Line number in the Monty file.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	(void)line_number;

	if (top == NULL)
	{
		handle_error("can't pint, stack empty", *stack, bus.file);
	}
	printf("%d\n", top->n);
}
