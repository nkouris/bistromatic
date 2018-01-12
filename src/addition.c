/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:19:05 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/11 16:41:19 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		addition(t_list **head)
{
	t_list	*result;
	t_list	*operand1;
	t_list	*operand2;
	int		error;
	int		max;

	operand1 = 0;
	operand2 = 0;
	error = 1;
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	operandsplit(head, &operand1, &operand2);
	max = maxindex(&operand1, &operand2);
	error = subaddtrack(result, operand1, operand2, max)
	lstdel(*head);
	lstdel(operand1);
	lstdel(operand2);
	(*head) = result;
	return (error);
}

int		subaddtrack(t_list **result, t_list *operand1, t_list *operand2, int max)
{
	if (max = 1)
	{
		if (!operand1->isneg && operand2->isneg)
			return (runsub(result, operand1, operand2));
		if (operand1->isneg || (operand1->isneg && operand2->isneg))
			(*result)->isneg = 1;
		return (runadd(result, operand1, operand2));
	}
	else if (max = 2)
	{
		if (!operand2->isneg && operand1->isneg)
			return (runsub(result, operand2, operand1));
		if (operand2->isneg || (operand2->isneg && operand1->isneg))
			(*result)->isneg = 1;
		return (runadd(result, operand2, operand1));
	}
	return (1);
}

int		runadd(t_list **result, t_list *top, t_list *bottom)
{
	int	add;
	int	bottomsym;
	int	topsym;
	int	base;

	add = 0;
	base = bottom->base;
	while ((*result)->remainder || top)
	{
		if (!((*result)->prev = (t_list *)ft_memalloc(sizeof(t_list))))
			return (0);
		((*result)->isneg) ? ((*result)->prev)->isneg = 1 : (*result);
		!bottom ? (bottomsym = 0) : (bottomsym = bottom->symbolindex);
		!top ? (topsym = 0) : (topsym = top->symbolindex);
		add = bottomsym + (topsym + (*result)->remainder);
		if (add > base) 
			addremainder(result, add, base);
		else
			(*result)->symbolindex = add;
		!bottom ? bottom : (bottom = bottom->prev);
		!top ? top : (top = top->prev);
		((*result)->prev)->next = (*result);
		(*result) = (*result)->prev;
	}
	return (1);
}

void	addremainder(t_list **result, int add, int base)
{
	(*result)->symbolindex = add - base;
	add = ((add - (add - base)) / base);
	((*result)->prev)->remainder = ((base - (add - base)) / base);
}
