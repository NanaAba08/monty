#include "monty.h"

// Function to push an element onto the stack
void push(stack_t **stack, unsigned int line_number, int value) 
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
 {
        fprintf(stderr, "Error: Memory allocation failed at line %d\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}



void handle_error(const char *message, stack_t *stack, FILE *file) {
    fprintf(stderr, "L%d: %s\n", get_line_number(stack, file), message);
    free_stack(stack);
    if (file) {
        fclose(file);
    }
    exit(EXIT_FAILURE);
}



// Helper function to get the line number based on the file position
unsigned int get_line_number(stack_t *stack, FILE *file) {
    int line_number = 0;
    char input[100];
    fseek(file, 0, SEEK_SET);

    while (fgets(input, sizeof(input), file)) {
        line_number++;
        if (stack->n == line_number) {
            break;
        }
    }

    return line_number;
}
