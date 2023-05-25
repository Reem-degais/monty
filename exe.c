#include "monty.h"

int exe(char *buf, unsigned int count, stack_t **stack, FILE *file)
{
	instruction_t _opcode[] = {{"push", push}, {"pall", pall}};


	char *op;
	unsigned int i = 0;
	
	op = strtok(buf, " \n\t");
	h.arg = strtok(NULL, " \n\t");
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
			fclose(file);
			free(buf);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	return (1);
}
