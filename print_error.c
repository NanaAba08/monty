#include "monty.h"

/* Function to print error messages */
void print_error(unsigned int line_number, const char *message, const char *extra)
{
	fprintf(stderr, "L%u: %s", line_number, message);
	if (extra)
		fprintf(stderr, " %s", extra);
	fprintf(stderr, "\n");
}
