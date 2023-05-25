#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	/**else
		addqueue(head, n);*/
}



/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int counter)
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


/**
 * pint - check the code
 * @stack: head of double linked list
 * @number: to follow the shape
 * Return: number of nodes
 */
void	pint(stack_t **head, unsigned int counter)
{
	stack_t	*tmp = *head;

	if (tmp)
		fprintf(stdout, "%d\n", tmp->n);
	else 
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	pop(stack_t **head, unsigned int counter)
{
	stack_t	*tmp;
	stack_t	*new_head;

	tmp = *head;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_head = tmp->next;
	free(tmp);
	if (new_head)
		new_head->prev = NULL;
	*head = new_head;
}
