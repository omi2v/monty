#include "monty.h"
glo_t glo;

/**
 * op_push - function that push an element to the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!stack)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		free_buff();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_buff();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = glo.node_data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;

		(*stack)->prev = new_node;

		*stack = new_node;
	}
	else
	{
		*stack = new_node;
	}
}

/**
 * op_pall - function that prints out all the elements of a linked list
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	*stack = tmp;
}

/**
 * op_pint - function that prints the value at the top of the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pop - function that removes the top element of the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack)
	{
		dprintf(2, "L%u: can't pop an empty stack", line_number);
		free_buff();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
		break;
	}
}

/**
 * op_add - adds the first two nodes together
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 * Return: nothing
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int count = 0;
	int sum = 0;
	(void)line_number;

	if (!stack && (*stack)->next)
	{
		dprintf(2, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	while (*stack && (*stack)->next)
	{
		if (count == 2)
		{
			break;
		}
		sum += (*stack)->n;
		*stack = (*stack)->next;

		count++;
	}
	*stack = temp;

	(*stack)->next->n = sum;
	(*stack)->next->prev = NULL;
	free(*stack);
	*stack = (temp)->next;
}
