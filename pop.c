#include "monty.h"
/**
 * pop - Removes the top element of the stack (pop opcode).
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		handle_error(line_number, "can't pop an empty stack", *stack, bus.file);
		return;
	}

	*stack = top->next;
	if (top->next != NULL)
	{
		top->next->prev = NULL;
	}
	free(top);
}
