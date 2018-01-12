/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 10:10:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/10 10:10:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	solve_equation(char	op, t_list **start)
{
	t_list *top;
	t_list *bottom;

	top = *start;
	while ((*start)->next != NULL)
		*start = (*start)->next;
	bottom = *start;
	
	if (op == '+')
		runadd(start, top, bottom);
	//	if (op == '%')
	//		modulo(start);
	//	if (op == '/')
	//		division(start);
	if (op == '*')
		runmul(start, top, bottom);
	if (op == '-')
		runsub(start, top, bottom);
}

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
//	printf("%sIM IN PRECEDENCE: op1 %c, op2 %c\n%s", MAGNETA, op1, op2, NORMAL);
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
//	printf("%sPRECEDENCE: %d\n%s", MAGNETA, (int)(op1 - op2), NORMAL);
	return((int)(op1 - op2));
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
