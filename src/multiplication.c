/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 00:34:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/11 01:54:06 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		multiplication(t_list **head)
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
	max = maxindex(&operand1, &operand2);
	error = submultrack(result, operand1, operand2, max);
	lstdel(*head);
	lstdel(operand1);
	lstdel(operand2);
	(*head) = result;
	return (error);
}

int		submultrack(t_list **result, t_list *operand1, t_list *operand2, int max)
{
	if (operand1->isneg || operand2->isneg)
		(*result)->isneg = 1;
	if (max = 1)
		return (runmul(result, operand1, operand2));
	else if (max = 2)
		return (runmul(result, operand2, operand1));
	return (1);
}

int		runmul(t_list **result, t_list *top, t_list *bottom)
{
	t_list	*resultpre;
	int	mul;
	int	bottomsym;
	int	topsym;
	int	base;
	int	addlevel;

	mul = 0;
	addlevel = 1;
	base = bottom->base;
	while ((*result)->remainder || top)
	{
		!bottom ? (bottomsym = 1) : (bottomsym = bottom->symbolindex);
		// magnitude track
		addlevel > 1 ? resultpre = (*result) : resultpre = 0;
		// add a magnitude pusher as the loop progresses through symbol indices
		while ((*result)->remainder || top)
		{
			if (!((*result)->prev = (t_list *)ft_memalloc(sizeof(t_list))))
				return (0);
			if (addlevel > 1 && !(*result)->next)
				mulmagpush(result, addlevel);
			((*result)->isneg) ? ((*result)->prev)->isneg = 1 : (*result);
			!top ? (topsym = 0) : (topsym = top->symbolindex);
			mul = (bottomsym * topsym) + (*result)->remainder;
			if (mul > base)
				mulremainder(result, mul, base);
			else
				(*result)->symbolindex = mul;
			!top ? top : (top = top->prev);
			((*result)->prev)->next = (*result);
			(*result) = (*result)->prev;
		}
		if (addlevel++ > 1)
		// add difference between magnitude levels, using result for next calc
			runadd(result
		!bottom ? bottom : (bottom = bottom->prev);
	}
	return (1);
}

int		mulmagpush(t_list **result, int addlevel)
{
	// complete to push level, and apply result accordingly
	addlevel -= 1;
	while (addlevel--)
	{
		if (!(*result)->prev = 
}

void	mulremainder(t_list **result, int mul, int base)
{
	(*result)->symbolindex = mul % base;
	((*result)->prev)->remainder = mul / base;
}
