#include "monty.h"

/**
 * main - main function of monty.
 * @argc: the number of argument.
 * @argv: monty file.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *buf = NULL;
	size_t size = 0, read_line = 1;
	unsigned int count = 0;
	stack_t *stack = NULL;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		read_line = getline(&buf, &size, file);
		count++;
		if (read_line > 0)
			exe(buf, count, &stack);

	}
        free(buf);	

	fclose(file);
	return (0);
}
