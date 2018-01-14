/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 00:34:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 22:30:03 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		multrack(t_list **res, t_list *op1, t_list *op2, int max)
{
	printf("MulTRack\n");
	if ((op1->isneg || op2->isneg) && !(op1->isneg && op2->isneg))
		(*res)->isneg = 1;
	if (max == 1)
		return (runmul(res, op1, op2));
	else if (max == 2)
		return (runmul(res, op2, op1));
	return (0);
}

int		runmul(t_list **res, t_list *top, t_list *bot)
{
	int		mul;
	int		botsym;
	int		topsym;
	int		base;
	int		addlevel;
	t_list	*ttop;

	mul = 0;
	addlevel = 0;
	base = (*res)->base;
	ttop = top;
printf("Run mul\n");
	while (bot)
	{
		botsym = bot->symbolindex;
		while ((*res)->remainder || top)
		{
			if (!listhookup(res, 1, 0))
				return (0);
			((*res)->isneg) ? ((*res)->prev)->isneg = 1 : ((*res)->prev)->isneg;
			!top ? (topsym = 0) : (topsym = top->symbolindex);
	printf("topsym: %d * botsym: %d\n", topsym, botsym);
			mul = (botsym * topsym) + (*res)->remainder;
			if (mul >= base)
				mulremainder(res, mul, base);
			else
				(*res)->symbolindex = mul;
			!top ? top : (top = top->prev);
			(*res) = (*res)->prev;
//			printf("addlevel: %d\n", addlevel);
		}
		addlevel++;
//printf("addlevel: %d\n", addlevel);
		bot = bot->prev;
		top = ttop;
		if (addlevel > 1)
		{
//			printf("grow mag\n");
			mulmagpush(res, addlevel);
			sendoperands(res, '+', 0);
//			printf("level added\nres: %p\n", (*res));
		}
		if (bot)
		   	mulmagpush(res, addlevel);
	}
	printf("MulComplete\n");
	return (1);
}

int		mulmagpush(t_list **res, int addlevel)
{
	int		temp;

	temp = 0;
printf("magpush: %d\n", addlevel);
	if (addlevel)
	{
		(*res)->na = 1;
		while (addlevel-- > -1)
		{
			if (!listhookup(res, 1, 0))
				return (0);
			((*res)->isneg) ? ((*res)->prev)->isneg = 1 : ((*res)->prev)->isneg;
			(*res) = (*res)->prev;
			addlevel >= 0 ? (*res)->symbolindex = 0 : (*res)->symbolindex;
		}
	}
	if (temp > 1)
	{
		while ((*res)->next)
			(*res) = (*res)->next;
	}
	return (1);
}

void	mulremainder(t_list **res, int mul, int base)
{
	(*res)->symbolindex = mul % base;
	((*res)->prev)->remainder = mul / base;
}
