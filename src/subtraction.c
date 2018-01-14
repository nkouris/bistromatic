/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:07:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/14 07:08:14 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		subtrack(t_list **res, t_list *op1, t_list *op2, int max)
{
	if (max == 1)
	{
		if ((op1->isneg && !op2->isneg)
			|| (op1->isneg && op2->isneg))
			(*res)->isneg = 1;
		if ((!op1->isneg && !op2->isneg)
			|| (op1->isneg && op2->isneg))
			return (runsub(res, op1, op2));
		else
			return (runadd(res, op1, op2));
	}
	else if (max == 2)
	{
		if ((!op2->isneg && !op1->isneg)
			|| (!op2->isneg && op1->isneg))
			(*res)->isneg = 1;
		if ((!op2->isneg && !op1->isneg)
			|| (op2->isneg && op1->isneg))
			return (runsub(res, op2, op1));
		else
			return (runadd(res, op2, op1));
	}
	return (0);
}

int		runsub(t_list **res, t_list *top, t_list *bot)
{
	int	sub;
	int	botsym;
	int	topsym;
	int	base;

	sub = 0;
	base = (*res)->base;
	printf("runsub\n");
	while ((*res)->remainder || top)
	{
		if (!listhookup(res, 1, 0))
			return (0);
		((*res)->isneg) ? ((*res)->prev)->isneg = 1 : ((*res)->prev)->isneg;
//	printf("ISNEG: %d\n", (*res)->isneg);
		!bot ? (botsym = 0) : (botsym = bot->symbolindex);
		!top ? (topsym = 0) : (topsym = top->symbolindex);
//	printf("sub %d - (%d + %d)\n", topsym, botsym, (*res)->remainder);
		sub = topsym - (botsym + (*res)->remainder);
//	printf("sub: %d\n",sub);
		if (sub < 0)
		{
			(*res)->symbolindex = base + sub;
			((*res)->prev)->remainder = 1;
		}
		else
			(*res)->symbolindex = sub;
		!bot ? bot : (bot = bot->prev);
		!top ? top : (top = top->prev);
		(*res) = (*res)->prev;
		
	}
	printf("END OF SUB\n");
	return (1);
}
