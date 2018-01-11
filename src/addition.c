/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:19:05 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/10 21:07:15 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		addition(t_list **head)
{
	t_list	*result;
	t_list	*operand1;
	t_list	*operand2;
	int		error;

	operand1 = 0;
	operand2 = 0;
	error = 1;
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	operandsplit(head, &operand1, &operand2);
	operandlen(&operand1, &operand2);
	error = subaddtrack(result, operand1, operand2)
	if (!(*result)->next && (operand1->numlen > operand2->numlen))
		error = runadd(&result, operand1, operand2);
	else if (!(*result)->next)
		error = runadd(&result, operand2, operand1);
	lstdel((*head));
	lstdel(operand1);
	lstdel(operand2);
	(*head) = result;
	return (error);
}

int		subaddtrack(t_list *operand1, t_list *operand2, t_list **result)
{
	int	error;

	error = 1;
	if ((operand1->numlen > operand2->numlen) && operand2->isneg)
	{
		operand2->isneg = 0;
		runsubtract(result, operand1, operand2);
	}
	else if ((operand2->numlen > operand1->numlen) && operand1->isneg)
	{
		operand1->isneg = 0;
		runsubtract(result, operand2, operand1);
	}
	return (error);
}

// ONLY GOOD FOR POSITIVE NUMBERS AT THE MOMENT

int		runadd(t_list **result, t_list *top, t_list *bottom)
{
	int		add;
	int		bottomsym;
	int		topsym;
	int		base;

	add = 0;
	base = bottom->base;
	if ((*result)->isneg)
		negative = 1;
	while ((*result)->remainder || top)
	{
		if (!((*result)->prev = (t_list *)ft_memalloc(sizeof(t_list))))
			return (0);
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
	if (//NEG VAR)
		(*result)->isneg = 1;
	return (1);
}

void	addremainder(t_list **result, int add, int base)
{
	(*result)->symbolindex = add - base;
	add = ((add - (add - base)) / base);
	((*result)->prev)->remainder = ((base - (add - base)) / base);
}
