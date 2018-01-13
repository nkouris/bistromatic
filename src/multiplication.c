/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 00:34:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 03:40:26 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		multrack(t_list **result, t_list *operand1, t_list *operand2, int max)
{
	if (operand1->isneg || operand2->isneg)
		(*result)->isneg = 1;
	if (max == 1)
		return (runmul(result, operand1, operand2));
	else if (max == 2)
		return (runmul(result, operand2, operand1));
	return (0);
}

int		runmul(t_list **result, t_list *top, t_list *bottom)
{
	int		mul;
	int		bottomsym;
	int		topsym;
	int		base;
	int		addlevel;
	t_list	*ttop;

	mul = 0;
	addlevel = 0;
	base = (*result)->base;
	ttop = top;
	printf("Run mul\n");
	while (bottom)
	{
		bottomsym = bottom->symbolindex;
		while ((*result)->remainder || top)
		{
			if (!listhookup(result, 1, 0))
				return (0);
			((*result)->isneg) ? ((*result)->prev)->isneg = 1 : ((*result)->prev)->isneg;
			!top ? (topsym = 0) : (topsym = top->symbolindex);
		printf("topsym: %d * botsym: %d\n", topsym, bottomsym);
			mul = (bottomsym * topsym) + (*result)->remainder;
			if (mul >= base)
				mulremainder(result, mul, base);
			else
				(*result)->symbolindex = mul;
			!top ? top : (top = top->prev);
			(*result) = (*result)->prev;
			printf("addlevel: %d\n", addlevel);
		}
		addlevel++;
printf("addlevel: %d\n", addlevel);
		bottom = bottom->prev;
		top = ttop;
		if (addlevel > 1)
		{
			printf("grow mag\n");
			mulmagpush(result, addlevel);
			sendoperands(result, '+', 0);
			printf("level added\nresult: %p\n", (*result));
		}
		if (bottom)
		   	mulmagpush(result, addlevel);
	}
	return (1);
}

int		mulmagpush(t_list **result, int addlevel)
{
	int		temp;

	temp = 0;
printf("magpush: %d\n", addlevel);
	if (addlevel)
	{
		(*result)->na = 1;
		while (addlevel-- > -1)
		{
			if (!listhookup(result, 1, 0))
				return (0);
			((*result)->isneg) ? ((*result)->prev)->isneg = 1 : ((*result)->prev)->isneg;
			(*result) = (*result)->prev;
			addlevel >= 0 ? (*result)->symbolindex = 0 : (*result)->symbolindex;
		}
	}
	if (temp > 1)
	{
		while ((*result)->next)
			(*result) = (*result)->next;
	}
	return (1);
}

void	mulremainder(t_list **result, int mul, int base)
{
	(*result)->symbolindex = mul % base;
	((*result)->prev)->remainder = mul / base;
}
