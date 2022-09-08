#include "monty.h"
glo_t glo;

/**
 * get_opcode - that selects the correct function to perform the
 * operation asked by the user.
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: the function pointer to an operator
 */

int get_opcode(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"add", op_add},
		{"swap", op_swap},
		{"nop", op_nop},
		{NULL, NULL}};
	int i = 0;

	while (i != 7)
	{
		if (!(strcmp(ops[i].opcode, glo.bigb[0])))
		{
			ops[i].f(stack, line_number);
			break;
		}
		i++;
	}
	return (1);
}
