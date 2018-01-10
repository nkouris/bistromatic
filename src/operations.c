/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/09 17:52:33 by nkouris          ###   ########.fr       */
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

int		operandsplit(t_list **head, t_list **operand1, t_list **operand2)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (!(*head)->isoperator || !(*head)->if_na)
	{
		temp = (*head);
		temp->prev = 0;
		if (temp->value == '-')
		{
			i = 1;
			temp = temp->next;
			remove_onenode((*head));
		}
		while (!(temp->if_na))
		{
			if (i)
				temp->isneg = 1;
			temp = temp->next;
		}
		if (temp->next)
			head = temp->next;
		temp->next = 0;
		(!operand1) ? (*operand1) = temp->prev : (*operand2) = temp->prev;
	}
}

int		operandlen(t_list **operand1, t_list **operand2)
{
	t_list	*temp;
	int		i;

	temp = (*operand1);
	i = 0;
	while (temp->next)
		i++;
	(*operand1)->numlen = i;
	temp = (*operand2);
	i = 0;
	while (temp->next)
		i++;
	(*operand2)->numlen = i;
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

int		remaindercalc(int result, int base)
{
	int	i;

	i = 1;
	while (base < result)
		base = base * i++;
	return (base - result);
}
