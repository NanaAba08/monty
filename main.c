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
	FILE *file;

	bus.file = file;
	char content[1024];
	size_t size = sizeof(content);
	ssize_t read_line;
	stack_t *stack = NULL;
	unsigned int counter = 0;

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
			execute_instruction(bus.content, &stack, counter, file);
		}
	}

	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
