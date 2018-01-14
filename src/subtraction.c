/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:07:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 18:05:38 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		subtrack(t_list **result, t_list *op1, t_list *op2, int max)
{
	if (max == 1)
	{
		if ((op1->isneg && !op2->isneg)
			|| (op1->isneg && op2->isneg))
			(*result)->isneg = 1;
		if ((!op1->isneg && !op2->isneg)
			|| (op1->isneg && op2->isneg))
			return (runsub(result, op1, op2));
		else
			return (runadd(result, op1, op2));
	}
	else if (max == 2)
	{
		if ((!op2->isneg && !op1->isneg)
			|| (!op2->isneg && op1->isneg))
			(*result)->isneg = 1;
		if ((!op2->isneg && !op1->isneg)
			|| (op2->isneg && op1->isneg))
			return (runsub(result, op2, op1));
		else
			return (runadd(result, op2, op1));
	}
	return (0);
}

int		runsub(t_list **result, t_list *top, t_list *bot)
{
	int	sub;
	int	botsym;
	int	topsym;
	int	base;

	sub = 0;
	base = (*result)->base;
	printf("runnsub\n");
	while ((*result)->remainder || top)
	{
		if (!listhookup(result, 1, 0))
			return (0);
		((*result)->isneg) ? ((*result)->prev)->isneg = 1 : ((*result)->prev)->isneg;
	printf("ISNEG: %d\n", (*result)->isneg);
		!bot ? (botsym = 0) : (botsym = bot->symbolindex);
		!top ? (topsym = 0) : (topsym = top->symbolindex);			//segfault here when -2-4
	printf("sub %d - (%d + %d)\n", topsym, botsym, (*result)->remainder);
		sub = topsym - (botsym + (*result)->remainder);
		printf("sub: %d\n",sub);
		if (sub < 0)
		{
			(*result)->symbolindex = base + sub;
			((*result)->prev)->remainder = 1;
		}
		else
			(*result)->symbolindex = sub;
		!bot ? bot : (bot = bot->prev);
		!top ? top : (top = top->prev);
		(*result) = (*result)->prev;
		
	}
	printf("END OF SUB\n");
	return (1);
}
