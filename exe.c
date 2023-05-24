#include "monty.h"

int exe(char *buf, unsigned int count, stack_t **stack)
{
	instruction_t _opcode[] = {{"push", push}};


	char *op;
	int i = 0;



	op = strtok(buf, " ");
	h.arg = strtok(NULL, " ");
        while (_opcode[i].opcode && op)
	{
		if (strcmp(op, _opcode[i].opcode) == 0)
		{	
			_opcode[i].f(stack, count);
			return (0);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
			exit(EXIT_FAILURE);
		}
		i++;
		


        }
	return (1);
}
