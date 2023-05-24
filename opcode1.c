#include "monty.h"

void push(stack_t **head, unsigned int count)
{
	int n ;
	n = atoi(h.arg);
       if (isdigit(n) == 0)
       {
	       fprintf(stderr, "L%d: usage: push integer\n", count);
	       exit(EXIT_FAILURE);
       }
       else
	       addnode(head, n);
}
