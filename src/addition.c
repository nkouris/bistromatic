/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:19:05 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/10 14:37:06 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		addition(t_list **head)
{
	t_list *result;
	t_list *operand1;
	t_list *operand2;

	operand1 = 0;
	operand2 = 0;
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	operandsplit(head, &operand1, &operand2);
	operandlen(&operand1, &operand2);
	/*
	if ((operand1->numlen > operand2->numlen) && operand1->isneg)
		runsubtract(&result, operand1, operand2);
	else if ((operand2->numlen > operand1->numlen) && operand2->isneg)
		runsubtract(&result, operand2, operand1);
	*/
	if (operand1->numlen > operand2->numlen)
		runadd(&result, operand1, operand2);
	else
		runadd(&result, operand2, operand1);
//	lstdel((*head));
//	lstdel(operand1);
//	lstdel(operand2);

	(*head) = result;
	// FOR TESTING, REMOVE
//	readresult(result);
	return (1);
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
	return (1);
}

void	addremainder(t_list **result, int add, int base)
{
	(*result)->symbolindex = add - base;
	add = ((add - (add - base)) / base);
	((*result)->prev)->remainder = ((base - (add - base)) / base);
}
