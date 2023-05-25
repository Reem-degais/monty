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
	int sum;

	tmp = *head;
	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(h.file);
		free(h.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*head = tmp->next;
	free(tmp);
}

/**
 * nop -  doesn’t do anything..
 * @head: stack head.
 * @count: line_number.
 *  Return: no return.
 */
void nop(stack_t **head, unsigned int count)
{
	(void) head;
	(void) count;

}

/**
 * sub - adds the top two elements of the stack.
 * @head: stack head.
 * @count: line_number.
 *  Return: no return.
 */
void sub(stack_t **head, unsigned int count)
{
        stack_t *tmp;
        int sub;

        tmp = *head;
        if (!tmp || !tmp->next)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", count);
                fclose(h.file);
                free(h.buf);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        sub = tmp->next->n - tmp->n;
        tmp->next->n = sub;
        *head = tmp->next;
        free(tmp);
}
