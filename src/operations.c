/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/14 22:32:52 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		sendoperands(t_list **head, char op, bool delhead)
{
	t_list	*result;
	t_list	*op1;
	t_list	*op2;
	int		error;
	int		max;

	op1 = 0;
	op2 = 0;
	error = 1;
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list)))
		|| !(result->basekey = (*head)->basekey)
		|| !(result->base = (*head)->base)
		|| !(listhookup(&result, 0, 1)))
		return (0);
//printf("head: %p\n", (*head));
	operandsplit(*head, &op1, &op2);
	max = maxindex(&op1, &op2, op);
	moveto_order(&op1, &op2, 1);	
printf("Max: %d\n", max);
	op == '+' ? error = addtrack(&result, op1, op2, max) : error;
	op == '-' ? error = subtrack(&result, op1, op2, max) : error;
	op == '*' ? error = multrack(&result, op1, op2, max) : error;
//	op = '/' ? error = rundiv(&result, &op1, &op2, max) : error;
//	op = '%' ? error = rundiv(&result, &op1, &op2, max) : error;
	// delhead to protect recursion of division head, which is a composite of
	// the divisor and temporary dividend
//printf("delhead: %p\n", (*head));
	delhead ? error = lstdel(head) : error;
	(*head) = result;
	append(head);
//	printf("head ret: %p\nret next: %p\nret prev: %p\n", (*head), (*head)->next, (*head)->prev);
	return (error);
}

int		operandsplit(t_list *head, t_list **op1, t_list **op2)
{
	t_list	*temp;
	int		i;

printf("StartSplit\n");
	while (!(*op2))
	{
		temp = head;
//printf("incominisneg: %d\n", head->isneg);
		temp->prev = 0;
		temp->isneg ? (i = 1) : (i = 0);
		if (temp->value == '-')
		{
//	printf("is neg\n");
			i = 1;
			temp = temp->next;
			temp->prev = 0;
		}
		while (!(temp->na))
		{
			if (i)
				temp->isneg = 1;
printf("%sindex: \t\t\t\t%d\nbase: %d\nkey: %s\ntemp: %p\nprev: %p\nnext: %p\nnumlen: %d\n%s", GREEN, temp->symbolindex, temp->base, temp->basekey, temp, temp->prev, temp->next, temp->numlen, NORMAL);
			temp = temp->next;
		}
		if (temp->next)
			head = temp->next;
		(!(*op1)) ? ((*op1) = sym_lst(temp))
		: ((*op2) = sym_lst(temp));
printf("op1neg %d\n", (*op1)->isneg);
printf("^^^NewNum^^^\n");
printf("%sindex: \t\t\t\t%d\nbase: %d\nkey: %s\ntemp: %p\nprev: %p\nnext: %p\nnumlen: %d\n%s", GREEN, temp->symbolindex, temp->base, temp->basekey, temp, temp->prev, temp->next, temp->numlen, NORMAL);
	}
	return (1);
}

t_list	*sym_lst(t_list *temp)
{
	t_list	*op_lo;
	int		numlen;

	numlen = temp->numlen;
	op_lo = temp->prev;
	op_lo->next = 0;
	op_lo->numlen = numlen;
	return (op_lo);
}

int		maxindex(t_list **op1, t_list **op2, char op)
{
//	printf("op1: %p\nop2: %p\n", (*op1), (*op2));
	if (op == '/' || op == '%')
		return (3);
	if ((*op1)->numlen > (*op2)->numlen)
		return (1);
	else if ((*op2)->numlen > (*op1)->numlen)
		return (2);
	moveto_order(op1, op2, 0);
//printf("finding max\n");
	while ((*op1))
	{
//	printf("op1 sym max: %d%p\nop2 sym max: %d%p\n", (*op1)->symbolindex, (*op1), (*op2)->symbolindex, (*op2));
		if ((*op1)->symbolindex > (*op2)->symbolindex)
			return (1);
		if ((*op2)->symbolindex > (*op1)->symbolindex)
			return (2);
		if (!(*op1)->next || !(*op2)->next)
			break ;
		(*op1) = (*op1)->next;
		(*op2) = (*op2)->next;
	}
//printf("found max\n");
	return (1);
}

int		listhookup(t_list **node, bool prev, bool na)
{
printf("listhookup\n");
	if (prev)
	{
		if (!((*node)->prev = ft_memalloc(sizeof(t_list))))
			return (0);
		((*node)->prev)->next = (*node);
		((*node)->prev)->basekey = (*node)->basekey;
		((*node)->prev)->base = (*node)->base;
	}
	else
	{
		if (!((*node)->next = ft_memalloc(sizeof(t_list))))
			return (0);
		if (na)
			((*node)->next)->na = 1;
		((*node)->next)->prev = (*node);
		((*node)->next)->basekey = (*node)->basekey;
		((*node)->next)->base = (*node)->base;
	}
	return (1);
}

void	append(t_list **head)
{
	t_list *temp;
	int		numlen;
	
	numlen = 0;
	temp = (*head);
	if ((*head)->isneg)
	{
//		printf("addlen & neg\n");
		(*head)->value = '-';
	}
	else
	{
		(*head) = (*head)->next;
		free(temp);
		(*head)->prev = 0;
	}
	temp = (*head);
	while (temp)
	{
//		printf("addlen\n");
		indexsymbol(temp);
		if (!temp->next)
			temp->numlen = numlen;
		else
			temp->numlen = numlen++;
		temp = temp->next;
	}
	(*head)->numlen = numlen;
}

