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
 * sub - sub the top element from the second top element of the stack.
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
                fprintf(stderr, "L%d: can't sub, stack too short\n", count);
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

/**
 * _div - divs the second top element  by the top element of the stack.
 * @head: stack head.
 * @count: line_number.
 *  Return: no return.
 */
void _div(stack_t **head, unsigned int count)
{
        stack_t *tmp;
        int div;

        tmp = *head;
        if (!tmp || !tmp->next)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", count);
                fclose(h.file);
                free(h.buf);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
                fclose(h.file);
                free(h.buf);
                free_stack(*head);
                exit(EXIT_FAILURE);
	}
	else
	{
		div = tmp->next->n / tmp->n;
		tmp->next->n = div;
		*head = tmp->next;
		free(tmp);
	}
}

/**
 * mod - computes rest of div second top element by top element of the stack.
 * @head: stack head.
 * @count: line_number.
 *  Return: no return.
 */
void mod(stack_t **head, unsigned int count)
{
        stack_t *tmp;
        int mod;

        tmp = *head;
        if (!tmp || !tmp->next)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", count);
                fclose(h.file);
                free(h.buf);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
                fclose(h.file);
                free(h.buf);
                free_stack(*head);
                exit(EXIT_FAILURE);
	}
	else
	{
		mod = tmp->next->n % tmp->n;
		tmp->next->n = mod;
		*head = tmp->next;
		free(tmp);
	}
}
