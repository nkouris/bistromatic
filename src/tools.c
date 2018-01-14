/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 10:10:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/13 17:33:17 by nkouris          ###   ########.fr       */
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



/*
**	Function below:
**	-> 0 means positive;
**	-> 1 means negative;
*/

void	check_op(char *curr, t_list **head)
{
	*head = (*head)->next;
	while ((*head)->next != NULL)
	{
		if ((*head)->value == '-' && (*curr == '+' || *curr == '-'))
		{
			free_one_node((*head)->prev, *head, (*head)->next);
			*curr = (*curr == '-') ? '+' : '-';
		}
		*head = (*head)->next;
	}
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	if (*curr == '+' && (*head)->value == '-')
	{
		free_one_node(NULL, *head, (*head)->next);
		*curr = '-';
	}
	head = &(*head);
}


