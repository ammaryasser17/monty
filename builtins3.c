#include "monty.h"

/**
 * div_m - divs 2dn top node by the top element of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void div_m(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "div");
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		op_e(line_number, "div");
	else
	{
		if (temp->n == 0)
			div_e(line_number);
		temp2->n = temp2->n / temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}



}
/**
 * mod_m - mod 2dn top node by the top element of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void mod_m(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(line_number, "mod");
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		op_e(line_number, "mod");
	else
	{
		temp2->n = temp2->n % temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}

/**
 * pstr_t - prints the string starting at the top of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void pstr_t(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}


void rotrl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = (*stack)->next;
	temp2 = *stack;

	while (temp->next != NULL)
	{
		temp = temp->next->next;
	}
	temp->prev = NULL;
	temp2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp2;
	*stack = temp;
	(void)line_number;
}
