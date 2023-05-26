#include "monty.h"

/**
 * pint - prints the value at the top of the stack.
 * @head: stack head.
 * @count: line_number.
 * Return: no return.
 */
void pint(stack_t **head, unsigned int count)
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
 * pall - prints all the values on the stack.
 * @head: stack head.
 * @count: no used.
 * Return: no return.
*/
void pall(stack_t **head, unsigned int count)
{
	stack_t *tmp;
	(void)count;

	tmp = *head;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
