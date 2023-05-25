#include "monty.h"
/**
* exe - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exe(char *buf, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opins[] = {{"push", push}, {"pall", pall}, 
	      {"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add},
	      {"nop", nop}, {"sub", sub}, {"div", _div}, {"mod", mod},
	      {"mul", mul}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
	      {"rotr", rotr}, {"stack", _stack}, {"queue", queue}};
	unsigned int i = 0;
	char *op;

	op = strtok(buf, " \n\t");
	if (op && op[0] == '#')
		return (0);
	h.arg = strtok(NULL, " \n\t");
	while (opins[i].opcode && op)
	{
		if (strcmp(op, opins[i].opcode) == 0)
		{	opins[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opins[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(buf);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

