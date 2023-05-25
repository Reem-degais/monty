#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **head, unsigned int count)
{
	int n, i = 0, flag = 0;

	if (h.arg)
	{
		if (h.arg[0] == '-')
			i++;
		for (; h.arg[i] != '\0'; i++)
		{
			if (h.arg[i] > 57 || h.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(h.file);
			free(h.buf);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(h.file);
		free(h.buf);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(h.arg);
	if (h.lifi == 0)
		addnode(head, n);
	/**else
		addqueue(head, n);*/
}



/**
 * pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

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
void	pint(stack_t **head, unsigned int count)
{
	stack_t	*tmp = *head;

	if (tmp)
		fprintf(stdout, "%d\n", tmp->n);
	else 
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(h.file);
		free(h.buf);
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
void	pop(stack_t **head, unsigned int count)
{
	stack_t	*tmp;
	stack_t	*new_head;

	tmp = *head;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(h.file);
		free(h.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_head = tmp->next;
	free(tmp);
	if (new_head)
		new_head->prev = NULL;
	*head = new_head;
}

/**
 * swap - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	swap(stack_t **head, unsigned int count)
{
	stack_t	*tmp;
	int sp;

	tmp = *head;
	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(h.file);
		free(h.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	sp = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = sp;
}

