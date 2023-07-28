#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>

/**
  * main - Entry point
  * @argc: Number of arguments
  * @argv: Arguments
  * Return: Success
  */
bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	/*LE *file;
	char *content = NULL;
	size_t size = 0;
	ssize_t read_input;
	stack_t *stack = NULL;
	unsigned int counter = 0;*/

	FILE *file;
	    char *content = NULL;
	        size_t content_size = BUFFER_SIZE;
		    stack_t *stack = NULL;
		        unsigned int counter = 0;
	

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	content = (char *)malloc(content_size);
	    if (!content)
		        {
				        fprintf(stderr, "Error: Memory allocation failed\n");
					        fclose(file);
						        return (EXIT_FAILURE);
							    }

	        while (fgets(content, content_size, file) != NULL)
			    {
				            bus.content = content;
					            counter++;

						            execute_opcode(content, &stack, counter, file);
							        }

		    free(content);
		        free_stack(stack);
			    fclose(file);

			        return (EXIT_SUCCESS);
}
/*
	while ((read_input = getline(&content, &size, file)) != -1)
	{
		bus.content = content;
		counter++;

		if (read_input > 0)
		{
			execute_opcode(content, &stack, counter, file);
		}

		free(content);
		content = NULL;
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);*/

