#include "monty.h"

/**
  * free_stack - frees a doubly linked list
  * @stack: pointer to the head of the stack
  */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
