#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>

// ... (rest of the code remains the same)
//
// /**
//  * Prints the value at the top of the stack (pint opcode).
//   * @stack: Pointer to the top of the stack.
//    * @line_number: Line number in the Monty file.
//     */
//     void pint(stack_t **stack, unsigned int line_number)
//     {
//         stack_t *top = *stack;
//
//             while (top != NULL)
//                 {
//                         printf("%d\n", top->n);
//                                 return; // Only print the top value and exit the loop
//                                     }
//
//                                         handle_error(line_number, "can't pint, stack empty");
//                                             free_stack(*stack);
//                                                 exit(EXIT_FAILURE);
//                                                                                                  
