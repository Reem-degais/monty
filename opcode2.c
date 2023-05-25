#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @head: stack head.
 * @count: line_number.
 *  Return: no return.
 */
void add(stack_t **head, unsigned int count)
{
	stack_t	*tmp;
	int sum, l = 0;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(h.file);
		free(h.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*head = tmp->next;
}
