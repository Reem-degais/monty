#include "monty.h"

/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **head, unsigned int count)
{
	int n, i = 0, flag = 0;

	if(h.arg)
	{
		if (h.arg[0] == '-')
			i++;
		for (; h.arg[i] != '\0'; i++)
		{
			if (h.arg[i] > 57 || h.arg[i] < 48)
				flag = 1; 
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(h.file);
			free(h.buf);
			/*free_stack(*head);*/
			exit(EXIT_FAILURE); 
		}
	}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(h.file);
		free(h.buf);
		/*free_stack(*head);*/
		exit(EXIT_FAILURE); 
	}
	n = atoi(h.arg);
	/*if (bus.lifi == 0)*/
	addnode(head, n);
}



/**
 * pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
