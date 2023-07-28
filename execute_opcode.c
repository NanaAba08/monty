#include "monty.h"

/**
 * execute_opcodei executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: no return
 */
void execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"push", push},
       	{"pall", pall},
	{"pint", pint},
   {NULL, NULL}
    };

    char *op;
    
    int a, b;

    op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return;

    bus.arg = strtok(NULL, " \n\t");

    for (a = 0; opst[a].opcode; a++)
    {
        for (b = 0; op[b] && opst[a].opcode[b]; b++)
        {
            if (op[b] != opst[a].opcode[b])
                break;
        }

        if (!op[b] && !opst[a].opcode[b])
        {
            opst[a].f(stack, counter);
            return;
        }
    }

    if (op && !opst[a].opcode)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
}

