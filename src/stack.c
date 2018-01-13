/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:35:34 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/10 15:35:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	free_stack_node(t_operator **stack)
{
	t_operator *temp;
	
	temp = *stack;
	*stack = (*stack)->prev;
	free(temp);
	if ((*stack) != NULL)
//	{
		(*stack)->next = NULL;
//		printf("%sIM IN FREE: stack's pointing at: %c\n%s", BLUE, (*stack)->op, NORMAL);
//	}
//	printf("HERE I AM\n");
}

void	pop_stack(t_list **start, t_operator **stack)
{
//	printf("I'M IN POP_STACK! start->op: %c\n", (*stack)->op);
	sendoperands(start, (*stack)->op);
//	printf("I'M IN POP_STACK!2\n");
	free_stack_node(stack);
//	printf("I'M IN POP_STACK!3\n");
}

void	push_stack(char op, t_operator **stack)
{
	t_operator	*sign;
	t_operator	*head;
	
	head = *stack;
	sign = (t_operator *)malloc(sizeof(t_operator));
	sign->next = NULL;
	sign->op = op;
	if (head != NULL)
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = sign;
		sign->prev = *stack;
	}
	else
		sign->prev = NULL;
	*stack = sign;
	
//	//if you want to see how the stack is building, uncomment code below
//	while ((*stack)->prev != NULL)
//		*stack = (*stack)->prev;
//	printf("%sSTACK:\n", YELLOW);
//	printf("%c ", (*stack)->op);
//	while ((*stack)->next != NULL)
//	{
//		*stack = (*stack)->next;
//		printf("%c ", (*stack)->op);
//	}
//	printf("\n%s", NORMAL);
//	*stack = sign;
}
