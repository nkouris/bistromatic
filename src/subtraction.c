/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:07:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/10 22:05:48 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		subtraction(t_list **head)
{
	t_list	*result;
	t_list	*operand1;
	t_list	*operand2;
	int		error;
	int		max;

	operand1 = 0;
	operand2 = 0;
	error = 1;
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	operandsplit(head, &operand1, &operand2);
	/*
	operandlen(&operand1, &operand2);
	*/
	max = maxindex(&operand1, &operand2);
	// Use values as |absval|
	error = subnegtrack(&result, operand1, operand2);
	if (!(*result)->next)
		error = runsubtraction(&result, operand1, operand2);
	lstdel((*head));
	lstdel(operand1);
	lstdel(operand2);
	(*head) = result;
	return (error);
}

int		subnegtrack(t_list **result, t_list *operand1, t_list *operand2, int max)
{
	int	error;
	
	error = 1;
	if (max = 1)
	{
		if (!operand1->isneg && !operand2->inseg)
			runsub(result, operand1, operand2);
		else if (!operand1->isneg && operand2->isneg)
			runadd(result, operand1, operand2);
		else if (operand1->isneg && !operand2->isneg)
		{
			(*result)->isneg = 1;
			runadd(result, operand1, operand2);
		}
		else if (operand1->isneg && operand2->isneg)
		{
			(*result)->isneg = 1;
			runsub(result, operand1, operand2);
		}
	}
	else if (max = 2)
	{
		if (!operand2->isneg && !operand1->isneg)
		{
			(*result)->isneg = 1;
			runsub(result, operand2, operand1);
		}
		else if (operand2->isneg && !operand1->isneg)
			runadd(result, operand2, operand1);
		else if (!operand2->isneg && operand1->isneg)
		{
			(*result)->isneg = 1;
			runadd(result, operand2, operand1);
		}
		else if (operand2->isneg && !operand1->isneg)
		{
			(*result)->isneg = 1;
			runsub(result, operand2, operand1);
		}
	}
	return (error);
}

int		runsub(t_list **result, t_list *top, t_list *bottom)
{
	int	sub;
	int	bottomsym;
	int	topsym;
	int	base;

	sub = 0;
	base = bottom->base;
	while ((*result)->remainder || top)
	{
		if (!((*result)->prev = (t_list *)ft_memalloc(sizeof(t_list))))
			return (0);
		!bottom ? (bottomsym = 0) : (bottomsym = bottom->symbolindex);
		!top ? (topsym = 0) : (topsym = top->symbolindex);
		sub = (topsym + (*result)->remainder) - bottomsym
	}
}
