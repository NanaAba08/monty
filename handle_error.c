#include "monty.h"


 /**
  * Prints the error message along with the line number and additional info
   * (if available), and exits the program with EXIT_FAILURE.
    * @line_number: Line number in the Monty file.
     * @message: Error message to print.
      * @stack: Pointer to the top of the stack.
       * @file: Pointer to the file being processed.
        */
        void handle_error(unsigned int line_number, const char *message, stack_t *stack, FILE *file)
        {
            fprintf(stderr, "L%d: %s\n", line_number, message);
                free_stack(stack);
                    if (file)
                        {
                                fclose(file);
                                    }
                                        exit(EXIT_FAILURE);
                                        }

