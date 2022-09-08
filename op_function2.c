#include "monty.h"

/**
 * op_swap - function that swaps the first 2 nodes in a linked list
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1 = *stack;
	stack_t *node2 = (*stack)->next;
	stack_t *temp = NULL;
	stack_t *node3 = NULL;

	if (*stack && (*stack)->next)
	{
		node3 = node2->next;
		temp = node1->prev;

		node1->next = node3;
		node1->prev = node2;

		node2->prev = temp;
		node2->next = node1;

		if (node3 != NULL)
		{
			node3->prev = node1;
		}
		*stack = node2;
	}

	else
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_buff();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_nop - function that does nothing when executed
 * @stack: a pointer to the head of the linked list
 * @line_number: the line number
 * Return: nothing
 */

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}
