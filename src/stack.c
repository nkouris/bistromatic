/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:35:34 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/14 19:47:24 by nkouris          ###   ########.fr       */
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
		(*stack)->next = NULL;
}

void	pop_stack(t_list **head, t_operator **stack)
{
	t_list	*sub;
	t_list	*link;

printf("%sPopstack send, current operator: '%c'\nhead: %p\n%s", RED, (*stack)->op, (*head), NORMAL);
	link = sublist(head, &sub);
//printf("popHEAD: %p\n", (*head));
//printf("link: %p\n", link);
	if (link)
	{
		sendoperands(&sub, (*stack)->op, true);
//printf("joinlink: %p\nlinkprev: %p\nsub: %p\nsubindex: %d\n", link, link->prev, sub, sub->symbolindex);
		link->next = sub;
		sub->prev = link;
	}
	else
		sendoperands(head, (*stack)->op, true);
	free_stack_node(stack);
}

t_list		*sublist(t_list **head, t_list **sub)
{
	int		nas;
	t_list	*temp;
	t_list	*link;

	temp = (*head);
	nas = 0;
	while (temp->next)
		temp = temp->next;	
	while (temp->prev && nas < 2)
	{
//printf("temp: %p\n", temp);
		if ((temp->prev)->na)
			nas++;
		if (nas < 2)
			temp = temp->prev;
//printf("temp: %p\n", temp);
	}
	if (nas == 2)
	{
		link = temp->prev;
//	printf("head link: %p\n", (*head));
		temp->prev = 0;
//	printf("temp: %p\n", temp);
		(*sub) = temp;
//	printf("head link: %p\n", (*head));
		return (link);
	}
	else
		return (0);
}

void	push_stack(char op, t_operator **stack)
{
	t_operator	*sign;
	t_operator	*head;

printf("PushStack\n");	
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
}
