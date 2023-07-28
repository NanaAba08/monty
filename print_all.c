#include "monty.h"

/**
  * pall - prints all the elements in the stack
  * @stack: Stack
  * @line_number: no used
  * Return: Null
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
