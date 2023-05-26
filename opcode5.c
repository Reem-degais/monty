#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @head: stack head.
 * @count: line_number.
 * Return: no return.
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

/**
 * pop - removes the top element of the stack.
 * @head: stack head.
 * @count: line_number.
 * Return: no return.
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
