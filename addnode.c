#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{
	stack_t *new, *a = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit (EXIT_FAILURE);
	}
	if(a)
		a->prev =new;
        
	new->n = n;	
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
