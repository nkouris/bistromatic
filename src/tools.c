/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 10:10:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/14 07:08:16 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

/*
**	Function precedence returns
**	->	negative number when the last operator on a stack is more important
**		than a str[i]'s operator;
**	->	zero when the last operator on a stack has the same importance like
**		a str[i]'s operator;
**	->	positive number when is possible to push a str[i]'s operator on the
**		top of a stack;
*/

int		precedence(char op1, char op2)
{
	if (op1 == '-' || op1 == '+')
		op1 = '1';
	else if (op1 == '*' || op1 == '/' || op1 == '%')
		op1 = '2';
	else if (op1 == '(')
		op1 = '3';
	if (op2 == '(')
		op2 = '0';
	else if (op2 == '-' || op2 == '+')
		op2 = '1';
	else if (op2 == '*' || op2 == '/' || op2 == '%')
		op2 = '2';
	return ((int)(op1 - op2));
}

int		ft_find(char c, char *basekey)
{
	int	i;

	i = 0;
	while (basekey[i] != '\0')
		if (basekey[i++] == c)
			return (1);
	return (0);
}

void	moveto_order(t_list **op1, t_list **op2, bool low)
{
	if (low)
	{
		if (*op1)
		{
			while ((*op1)->next && !(*op1)->na)
				(*op1) = (*op1)->next;
		}
		if (*op2)
		{
			while ((*op2)->next && !(*op2)->na)
				(*op2) = (*op2)->next;
		}
	}
	else
	{
		if (*op1)
		{
			while ((*op1)->prev && !(*op1)->na)
				(*op1) = (*op1)->prev;
		}
		if (*op2)
		{
			while ((*op2)->prev && !(*op2)->na)
				(*op2) = (*op2)->prev;
		}
	}
}
