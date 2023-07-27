#include "monty.h"

/**
  * pall - A function that prints all the elements in the stack
  * @stack: Stack
  * @value: value of integer
  * Return: Null
  */
void pall(stack_t **stack, unsigned int line_number, int value)
{
	(void)value;
	(void)line_number;

	stack_t *current;
	*current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
