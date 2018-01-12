/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:07:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/11 18:28:32 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		subtrack(t_list **result, t_list *operand1, t_list *operand2, int max)
{
	if (max = 1)
	{
		if ((operand1->isneg && !operand2->isneg)
			|| (operand1->isneg && operand2->isneg))
			(*result)->isneg = 1;
		if ((!operand1->isneg && !operand2->inseg)
			|| (operand1->isneg && operand2->isneg))
			return (runsub(result, operand1, operand2));
		else
			return (runadd(result, operand1, operand2));
	}
	else if (max = 2)
	{
		if ((!operand2->isneg && !operand1->isneg)
			|| (!operand2->isneg && operand1->isneg)
			|| (operand2->isneg && !operand1->isneg))
			(*result)->isneg = 1;
		if ((!operand2->isneg && !operand1->isneg)
			|| (operand2->isneg && !operand1->isneg))
			return (runsub(result, operand2, operand1));
		else
			return (runadd(result, operand2, operand1));
	}
	return (0);
}

int		runsub(t_list **result, t_list *top, t_list *bottom)
{
	int	sub;
	int	bottomsym;
	int	topsym;
	int	base;

	sub = 0;
	base = bottom->base;
	while ((*result)->remainder || top)
	{
		if (!((*result)->prev = (t_list *)ft_memalloc(sizeof(t_list))))
			return (0);
		((*result)->isneg) ? ((*result)->prev)->isneg = 1 : (*result);
		!bottom ? (bottomsym = 0) : (bottomsym = bottom->symbolindex);
		!top ? (topsym = 0) : (topsym = top->symbolindex);
		sub = (topsym + (*result)->remainder) - bottomsym;
		if (sub < 0)
			sub = ((*result)->prev)->remainder;
		else
			sub = (*result)->symbolindex;
		!bottom ? bottom : (bottom = bottom->prev);
		!top ? top : (top = top->prev);
		((*result)->prev)->next = (*result);
		(*result) = (*result)->prev;
	}
	return (1);
}
