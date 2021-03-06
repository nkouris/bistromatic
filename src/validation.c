/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:01:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/14 23:34:05 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ------------------------ VALIDATION && REMALLOC -----------------------------
*/

#include "bsm.h"

#define OPERS(x)	x == '-' || x == '+' || x == '*' || x == '/' || x == '%'

int		brackets(char **head, char *base, char *new, int *brij)
{
	if ((*head)[brij[2]] == '(' || (*head)[brij[2]] == ')')
	{
		brij[0] += ((*head)[brij[2]] == '(') ? 1 : -1;
		if (((*head)[brij[2]] == 40 && ((brij[2] == 0) ||
			ft_find((*head)[brij[2] - 1], "+-*/%(") == 1) &&
			(ft_find((*head)[brij[2] + 1], "+-(") == 1 ||
			ft_find((*head)[brij[2] + 1], base) == 1)) ||
			(((*head)[brij[2]] == 41) && (brij[2] > 1) &&
			(ft_find((*head)[brij[2] - 1], base) == 1 ||
			(*head)[brij[2] - 1] == 41) &&
			(ft_find((*head)[brij[2] + 1], ")+-*/%") == 1 ||
			(*head)[brij[2] + 1] == '\0')))
			new[brij[3]++] = (*head)[brij[2]++];
		else
			return (-1);
	}
	return (0);
}

/*
**	Function below returns:
**	-> 2 when multiplication/division/modulo;
**	-> 1 when next number is positive;
**	-> 0 when input is invalid;
**	-> -1 when next number is negative;
*/

int		choose_sign(int *i, char *str, char *base)
{
	int		sign;

	sign = 1;
	if ((str[*i] == '*' || str[*i] == '%' || str[*i] == '/') && (*i > 0) &&
		(ft_find(str[*i - 1], base) == 1 || str[*i - 1] == 41) &&
<<<<<<< HEAD
		(ft_find(str[*i + 1], base) == 1 || str[*i + 1] == 40 || str[*i + 1] == '-'))
=======
		((ft_find(str[*i + 1], base) == 1 || str[*i + 1] == 40 || str[*i + 1] =='-')))
>>>>>>> 8fd8ed550c3d829662eb145cca6af7de680b654b
		return (2);
	else if (str[*i] == '+' || str[*i] == '-')
	{
		while (str[*i] == '+' || str[*i] == '-')
		{
			if (str[*i] == '+')
				;
			else if (str[*i] == '-')
				sign = (sign == -1) ? 1 : -1;
			*i += 1;
		}
		if (ft_find(str[*i], base) != 1 && ft_find(str[*i], "(") != 1)
			return (0);
	}
	else
		return (0);
	return (sign);
}

int		handle_signs(char **head, char *base, char *new, int *brij)
{
	if ((brij[1] = choose_sign(&(brij[2]), (*head), base)) != 0)
	{
		if (brij[1] == 1)
		{
			if (brij[3] != 0 && (ft_find(new[brij[3] - 1], base) == 1 ||
								new[brij[3] - 1] == 41))
				new[brij[3]++] = '+';
		}
		else if (brij[1] == 2)
			new[brij[3]++] = (*head)[brij[2]++];
		else
			new[brij[3]++] = '-';
	}
	else
		return (-1);
	return (0);
}

/*
**	variable int brij[4]:
**	- brij[0] <-- brackets;
**	- brij[1] <-- result;
**	- brij[2] <-- i (iterate through str);
**	- brij[3] <-- j (iterate through new);
*/

int		valid_input(char **head, char *base)
{
	static int	brij[4];
	char		*new;
//printf("Validating...\n");
	new = (char *)ft_memalloc(ft_strlen(*head) + 1);
	while ((*head)[brij[2]] != '\0' && (*head)[brij[2]] != '\n')
	{
//		printf("IM HERE, str[%d] = %c\n", brij[2], (*head)[brij[2]]);
		while ((*head)[brij[2]] == base[0] &&
			ft_find((*head)[brij[2] + 1], base) == 1)
			brij[2]++;
		while (ft_find((*head)[brij[2]], base) == 1)
			new[brij[3]++] = (*head)[brij[2]++];
		if ((brij[2] != 0 && (*head)[brij[2]] == '(') ||
			((*head)[brij[2]] == '(' && (*head)[brij[2] + 1] == ')'))
			if ((*head)[brij[2] + 1] == ')' ||
				ft_find((*head)[brij[2] - 1], base) != 0)
				return (-1);
		if (OPERS((*head)[brij[2]]) == 1)
			if (handle_signs(head, base, new, brij) == -1)
				return (-1);
		if (brackets(head, base, new, brij) == -1)
			return (-1);
	}
	new[brij[3]] = '\0';
	*head = new;
//	printf("HERE new = %s\n", new);
	return (brij[0] == 0 ? 0 : -1);
}

int		validation(char **head, char *base)
{
//	int res = 0;
	if (valid_input(head, base) == -1)
	{
		write(1, "syntax error\n", 13);
		return (-1);
	}
//	printf("%sBEFORE:	[%s]\n%s", YELLOW, *head, NORMAL);
	while ((remove_floats(head, base, 0, 0)) == 1)
		;
//	{
//		printf("REMOVE FLOATS RES = %d\n", res);
//		printf("%sAFTER:	[%s]\n\n%s", GREEN, *head, NORMAL);
//		printf("%sBEFORE:	[%s]\n%s", YELLOW, *head, NORMAL);
//	}
//	printf("REMOVE FLOATS RES = %d\n", res);
//	printf("%sAFTER:	[%s]%s\n", GREEN, *head, NORMAL);
	return (0);
}
