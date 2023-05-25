# include "monty.h"

/**
 * mul - mul the second top element with the top element of the stack.
 * @head: stack head.
 * @count: line_number.
 *  Return: no return.
 */
void mul(stack_t **head, unsigned int count)
{
        stack_t *tmp;
        int mul;

        tmp = *head;
        if (!tmp || !tmp->next)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", count);
                fclose(h.file);
                free(h.buf);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        mul = tmp->next->n * tmp->n;
        tmp->next->n = mul;
        *head = tmp->next;
        free(tmp);
}

/**
 * pchar - prints the char at the top of the stack.
 * @head: stack head.
 * @count: line_number.
 * Return: no return.
 */
void pchar(stack_t **head, unsigned int count)
{
	stack_t	*tmp = *head;


	
	if (tmp)
	{
		if (tmp->n > 127 || tmp->n < 0)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", count);
			fclose(h.file);
			free(h.buf);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		fprintf(stdout, "%c\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", count);
		fclose(h.file);
		free(h.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack.
 * @head: stack head.
 * @count: line_number.
 * Return: no return.
 */
void pstr(stack_t **head, unsigned int count)
{
	stack_t	*tmp = *head;
	(void) count;

	while (tmp)
	{
		if (tmp->next == NULL || tmp->n > 127 || tmp->n <= 0)
			break;
		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->next;
	}
	fprintf(stdout, "\n");
}
