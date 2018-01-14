/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:19:05 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 23:37:18 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		addtrack(t_list **result, t_list *op1, t_list *op2, int max)
{
	printf("start addition\n");
	if (max == 1)
	{
		printf("op1neg: %d\n", op1->isneg);
		if (op1->isneg || (op1->isneg && op2->isneg))
			(*result)->isneg = 1;
		if ((!op1->isneg && op2->isneg)
			|| (op1->isneg && !op2->isneg))
			return (runsub(result, op1, op2));
		return (runadd(result, op1, op2));
	}
	else if (max == 2)
	{
		if (op2->isneg || (op2->isneg && op1->isneg))
			(*result)->isneg = 1;
		if ((!op2->isneg && op1->isneg)
			|| (op2->isneg && !op1->isneg))
			return (runsub(result, op2, op1));
		return (runadd(result, op2, op1));
	}
	return (0);
}

int		runadd(t_list **result, t_list *top, t_list *bot)
{
	int	add;
	int	botsym;
	int	topsym;
	int	base;

	add = 0;
	base = (*result)->base;
	printf("runadd\n");
	printf("start top: %p\n", top);
	printf("start bot: %p\n", bot);
	while ((*result)->remainder || top)
	{
		if (!listhookup(result, 1, 0))
			return (0);
		((*result)->isneg) ? (((*result)->prev)->isneg) = 1 : ((*result)->prev)->isneg;
		!bot ? (botsym = 0) : (botsym = bot->symbolindex);
		!top ? (topsym = 0) : (topsym = top->symbolindex);
	printf("add %d + (%d + %d)", botsym, topsym, (*result)->remainder);
		add = botsym + (topsym + (*result)->remainder);
		if (add >= base)
			addremainder(result, add, base);
		else
			(*result)->symbolindex = add;
		printf("result of add: %d\n", (*result)->symbolindex);
		!bot ? bot : (bot = bot->prev);
		!top ? top : (top = top->prev);
		(*result) = (*result)->prev;
	}
	printf("END OF ADD\n");
	return (1);
}

void	addremainder(t_list **result, int add, int base)
{
	(*result)->symbolindex = add - base;
	add = ((add - (add - base)) / base);
	((*result)->prev)->remainder = ((base - (add - base)) / base);
}
