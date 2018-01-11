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

/* -------------------------- VALIDATION FUNCTIONS -------------------------- */

int		ft_strxcmp(char c, char *basekey)
{
	int	i;
	
	i = 0;
	while (basekey[i] != '\0')
		if (basekey[i++] == c)
			return (1);
	return (0);
}

# define OPERS(x)	x == '-' || x == '+' || x == '*' || x == '/' || x == '%'


/*
**	Function below returns:
**	-> 1 when input is invalid;
**	-> 0 when next number is positive;
**	-> -1 when next number is negative;
*/

int		decide_about_a_sign(int *i, int *j, char **str, char *basekey)
{
	int negative;
	
	negative = 0;
	
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '+')
			;
		else if (str[*i] == '-')
			negative = (negative == -1) ? 0 : -1;
		*i += 1;
		
	}
	if (str[*i] == '*' || str[*i] == '/' || str[*i] == '%')
	{

		if (*i < 1 || ft_strxcmp(str[*i - 1], basekey) == -1 ||
			ft_strxcmp(str[*i + 1], basekey) == -1)
			return (1);
	}
	return (negative);
}

int		validate_input(char **str, char *basekey)
{
	int	i;
	int j;
	int	brackets;
	char	*new;
	
	i = 0;
	j = 0;
	brackets = 0;
	new = (char *)malloc(ft_strlen(new) + 1);
	
	while (str[i] != '\0')
	{
		if (i != 0 && str[i] == '(')
			if (ft_strxcmp(str[i - 1], basekey) != 1)
				return (-1);
		if (str[i] == '(' || str[i] == ')')
			brackets += (str[i] == '(') ? 1 : -1;
//		if (OPERS(str[i]) == 1 && ft_strxcmp([i + 1], basekey) != 1)
//			return (-1);
		if (decide_about_a_sign() == -1)
			return (-1)
		new[j++] = str[i++];
	}
	new[j] = '\0'
	free(*str);
	*str = new;
	return (brackets == 0 ? 1 : -1);
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	printf("OUTPUT: %d\n", validate_input(*av[1], av[2]));
	return (0);
}
