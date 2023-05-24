#include "monty.h"

int exe(char *buf, unsigned int count, stack_t **stack)
{
	instruction_t _opcode[] = {{"push", push}};


	char *op;
	int i;


	op = strtok(buf, " ");
        while (_opcode[i].opcode && op)
	{
		if (strcmp(op, _opcode[i].opcode) == 0)
		{	
			_opcode[i].f(stack, count);
			return (0);
		}
		i++;
	}

	if (op && _opcode[i].opcode == NULL)
	{ 
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		exit(EXIT_FAILURE); 
	}
	return (1);



}
