/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 01:53:21 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		sendoperands(t_list **head, char op, bool delhead)
{
	t_list	*result;
	t_list	*operand1;
	t_list	*operand2;
	int		error;
	int		max;

	operand1 = 0;
	operand2 = 0;
	error = 1;
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list)))
		|| !(result->basekey = (*head)->basekey)
		|| !(result->base = (*head)->base)
		|| !(listhookup(&result, 0, 1)))
		return (0);
	operandsplit(head, &operand1, &operand2);
	max = maxindex(&operand1, &operand2, op);
printf("max: %d\n", max);
	op =='+' ? error = addtrack(&result, operand1, operand2, max) : error;
	op == '-' ? error = subtrack(&result, operand1, operand2, max) : error;
	op == '*' ? error = multrack(&result, operand1, operand2, max) : error;
//	op = '/' ? error = rundiv(&result, &operand1, &operand2, max) : error;
//	op = '%' ? error = rundiv(&result, &operand1, &operand2, max) : error;
	// delhead to protect recursion of division head, which is a composite of
	// the divisor and temporary dividend
// wrap lstdel with return value
//	printf("send inside4\n");
	delhead ? error = lstdel(head) : error;
	(*head) = result;
	append(head);
printf("%sNA: %p\nna: %d\nprev: %p\nnext: %p\n%s", BLUE, (*head), (*head)->na, (*head)->prev, (*head)->next, NORMAL);
	return (error);
}

int		operandsplit(t_list **head, t_list **operand1, t_list **operand2)
{
	t_list	*temp;
	int		i;

	i = 0;
printf("Start split\n");
	while (!(*operand2))
	{
		temp = (*head);
		temp->prev = 0;
		if (temp->value == '-')
		{
			printf("is neg\n");
			i = 1;
			temp = temp->next;
			ft_memdel((void **)&(*head));
		}
		while (!(temp->na))
		{
			if (i)
				temp->isneg = 1;
printf("%sindex: %d\nbase: %d\nkey: %s\ntemp: %p\nprev: %p\nnext: %p\n%s", GREEN, temp->symbolindex, temp->base, temp->basekey, temp, temp->prev, temp->next, NORMAL);
			temp = temp->next;
		}
		if (temp->next)
			(*head) = temp->next;
	printf("NEW NUM\n");
		(!(*operand1)) ? ((*operand1) = sym_lst(temp))
		: ((*operand2) = sym_lst(temp));
	}
	return (1);
}

t_list	*sym_lst(t_list *temp)
{
	t_list *op_lo;
	op_lo = temp->prev;
	free(temp);
	op_lo->next = 0;
	return (op_lo);
}

int		maxindex(t_list **operand1, t_list **operand2, char op)
{
	t_list *temp1;
	t_list *temp2;

	temp1 = (*operand1);
	temp2 = (*operand2);
	if (op == '/' || op == '%')
		return (4);
	while (temp1->prev && temp2->prev)
	{
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	if (temp1->prev && !temp2->prev)
		return (1);
	if (temp2->prev && !temp1->prev)
		return (2);
	while (!temp1->na)
	{
		if (temp1->symbolindex > temp2->symbolindex)
			return (1);
		if (temp2->symbolindex > temp1->symbolindex)
			return (2);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return (3);
}

int		listhookup(t_list **node, bool prev, bool na)
{
	if (!prev)
	{
		if (!((*node)->next = ft_memalloc(sizeof(t_list))))
			return (0);
		if (na)
			((*node)->next)->na = 1;
		((*node)->next)->prev = (*node);
		((*node)->next)->basekey = (*node)->basekey;
		((*node)->next)->base = (*node)->base;
	}
	else
	{
		if (!((*node)->prev = ft_memalloc(sizeof(t_list))))
			return (0);
		((*node)->prev)->next = (*node);
		((*node)->prev)->basekey = (*node)->basekey;
		((*node)->prev)->base = (*node)->base;
	}
	return (1);
}

void	append(t_list **head)
{
	t_list *temp;
	
	temp = (*head);
	temp->prev = 0;
	if ((*head)->isneg)
		(*head)->value = '-';
	else
	{
		(*head) = (*head)->next;
		free(temp);
		(*head)->prev = 0;
	}
	while ((*head)->next)
	{
		indexsymbol(*head);
		(*head) = (*head)->next;
	}
}

