#include "monty.h"

/**
  * main - Entry point
  * @argc: Number of arguments
  * @argv: Arguments
  * Return: Success
  */
bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char content[1024], *token;
	size_t size = sizeof(content);
	stack_t *stack = NULL;
	unsigned int counter = 0;
	bus.file = file;

	if (argc != 2 || !(file = fopen(argv[1], "r")))
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	while (fgets(content, size, file))
	{
		counter++;
		if ((token = strtok(content, " \t\n")) && token[0] != '#')
		{
			bus.content = token;
			execute_opcode(bus.content, &stack, counter, file);
		}
	}

	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
