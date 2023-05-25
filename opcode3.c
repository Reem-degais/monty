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
