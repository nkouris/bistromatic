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
	t_list *tets;
	
	tets = *start;
	op = 'b';
//	if (op == '+')
//		addition(start);
//	printf("IM IN SOLVE! op = %c\n", op);
	
	//	if (op == '%')
	//		modulo(start);
	//	if (op == '/')
	//		division(start);
	//	if (op == '*')
	//		multiplication(start);
	//	if (op == '-')
	//		substraction(start);
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
