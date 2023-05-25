#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct h_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @buf: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct h_s
{
	char *arg;
	FILE *file;
	char *buf;
	int flag;
}  h_t;
extern h_t h;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push(stack_t **head, unsigned int count);
void pall(stack_t **head, unsigned int count);
void pint(stack_t **head, unsigned int count);
int exe(char *buf, stack_t **head, unsigned int count, FILE *file);
void free_stack(stack_t *head);
void pop(stack_t **head, unsigned int count);
void swap(stack_t **head, unsigned int count);
void add(stack_t **head, unsigned int count);
void nop(stack_t **head, unsigned int count);
void sub(stack_t **head, unsigned int count);
void _div(stack_t **head, unsigned int count);
void mul(stack_t **head, unsigned int count);
void mod(stack_t **head, unsigned int count);
void pchar(stack_t **head, unsigned int count);
void pstr(stack_t **head, unsigned int count);
void rotl(stack_t **head, unsigned int count);
void rotr(stack_t **head, unsigned int count);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void queue(stack_t **head, unsigned int count);
void _stack(stack_t **head, unsigned int count);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif

