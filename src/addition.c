/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:19:05 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/09 18:19:35 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		addition(t_list **head)
{
	t_list *result;
	t_list *operand1;
	t_list *operand2;

	operand1 = 0;
	operand2 = 0;
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	operandsplit(head, &operand1, &operand2);
	operandlen(&operand1, &operand2);
	/*
	if ((operand1->numlen > operand2->numlen) && operand1->isneg)
		runsubtract(&result, operand1, operand2);
	else if ((operand2->numlen > operand1->numlen) && operand2->isneg)
		runsubtract(&result, operand2, operand1);
	*/
	if (operand1->numlen > operand2->numlen)
		runadd(&result, operand1, operand2);
	else
		runadd(&result, operand2, operand1);
}

// ONLY GOOD FOR POSITIVE NUMBERS AT THE MOMENT

int		runadd(t_list **result, t_list *top, t_list *bottom)
{
	t_list	*temp;
	int		add;
	int		bottomsym;
	int		base;

	add = 0;
	temp = top;
	base = bottom->base;
	while (bottom || temp->remainder)
	{
		!bottom ? bottomsym = 0 : bottomsym = bottom->symbolindex;
		add = bottomsym + (temp->symbolindex + temp->remainder);
		if (add > base)
		{
			(temp->prev)->remainder = remaindercalc(add, base)
			(*result)->symbolindex = add - base;
		}
		else
			(*result)->symbolindex = add;
		temp = temp->prev;
		bottom = bottom->prev;
		if (!((*result)->prev = (t_list *)ft_memalloc(sizeof(t_list))))
			return (0);
		((*result)->prev)->next = result;
		result = result->prev;
	}
	return (1);
}
