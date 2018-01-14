/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:41 by nkouris           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/01/13 23:43:44 by nkouris          ###   ########.fr       */
=======
/*   Updated: 2018/01/13 23:37:20 by nkouris          ###   ########.fr       */
>>>>>>> f01cfd5cd03ebdb6323fa50bb827891231bf7d33
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
	
<<<<<<< HEAD
=======
//	check_op(&op, head);
	printf("AFTER CHECKING OP: %c\n", op);
	
>>>>>>> f01cfd5cd03ebdb6323fa50bb827891231bf7d33
	printf("%sSENDLIST: ", CYAN);
	while ((*head)->next != NULL)
	{
		if ((*head)->na != 1)
			printf("%c -> ", (*head)->value);
		else
			printf("NA -> ");
		*head = (*head)->next;
	}
	if ((*head)->na != 1)
		printf("%c -> ", (*head)->value);
	else
		printf("NA -> ");
	printf("null\n");
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
	printf("FIRST: %c\n%s", (*head)->value, NORMAL);
	
	
	printf("send operands 1\n");
	if (!(result = (t_list *)ft_memalloc(sizeof(t_list)))
		|| !(result->basekey = (*head)->basekey)
		|| !(result->base = (*head)->base)
		|| !(listhookup(&result, 0, 1)))
		return (0);
	printf("send operands 2\n");
	operandsplit(head, &op1, &op2);
	printf("send operands 3\n");
	max = maxindex(&op1, &op2, op); 				//segfault when 2+2, 111+111, 23+23
	printf("send operands 4\n");
printf("max: %d\n", max);
	op == '+' ? error = addtrack(&result, op1, op2, max) : error;
	op == '-' ? error = subtrack(&result, op1, op2, max) : error;
	op == '*' ? error = multrack(&result, op1, op2, max) : error;
//	op = '/' ? error = rundiv(&result, &op1, &op2, max) : error;
//	op = '%' ? error = rundiv(&result, &op1, &op2, max) : error;
	// delhead to protect recursion of division head, which is a composite of
	// the divisor and temporary dividend
// wrap lstdel with return value
//	printf("send inside4\n");
printf("delhead: %p\n", (*head));
	delhead ? error = lstdel(head) : error;
	(*head) = result;
	append(head);
//printf("%sNA: %p\nna: %d\nprev: %p\nnext: %p\n%s", CYAN, (*head), (*head)->na, (*head)->prev, (*head)->next, NORMAL);
	return (error);
}

int		operandsplit(t_list **head, t_list **op1, t_list **op2)
{
	t_list	*temp;
	int		i;

printf("Start split\n");
	while (!(*op2))
	{
		temp = (*head);
	printf("incominisneg: %d\n", (*head)->isneg);
		temp->prev = 0;
		temp->isneg ? (i = 1) : (i = 0);
		if (temp->value == '-')
		{
	printf("is neg\n");
			i = 1;
			temp = temp->next;
			temp->prev = 0;
		}
		while (!(temp->na))
		{
			if (i)
				temp->isneg = 1;
printf("%sindex: \t\t\t\t%d\nbase: %d\nkey: %s\ntemp: %p\nprev: %p\nnext: %p\n%s", GREEN, temp->symbolindex, temp->base, temp->basekey, temp, temp->prev, temp->next, NORMAL);
			temp = temp->next;
		}
		if (temp->next)
			(*head) = temp->next;
printf("NEW NUM\n");
		(!(*op1)) ? ((*op1) = sym_lst(temp))
		: ((*op2) = sym_lst(temp));
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

int		maxindex(t_list **op1, t_list **op2, char op)
{
	(*op1) = (*op1);
	(*op2) = (*op2);
	if (op == '/' || op == '%')
		return (3);
	while ((*op1)->prev && (*op2)->prev)
	{
		(*op1) = (*op1)->prev;
		(*op2) = (*op2)->prev;
	}
	if ((*op1)->prev && !(*op2)->prev)
		return (1);
	if ((*op2)->prev && !(*op1)->prev)
		return (2);
	while ((*op1))
	{
		if ((*op1)->symbolindex > (*op2)->symbolindex)
			return (1);
		if ((*op2)->symbolindex > (*op1)->symbolindex)
			return (2);
		(*op1) = (*op1)->next;
		(*op2) = (*op2)->next;
	}
	return (1);
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
	int		numlen;
	
	numlen = 1;
	while ((*head)->next != NULL)
	{
		if ((*head)->na != 1)
			printf("%d -> ", (*head)->symbolindex);
		else
			printf("NA -> ");
		*head = (*head)->next;
	}
	if ((*head)->na != 1)
		printf("%d -> ", (*head)->symbolindex);
	else
		printf("NA -> ");
	printf("null\n");
	while ((*head)->prev != NULL)
		*head = (*head)->prev;


	temp = (*head);
	temp->prev = 0;
	if ((*head)->isneg)
	{
		printf("addlen & neg\n");
		(*head)->value = '-';
	}
	else
	{
		(*head) = (*head)->next;
		free(temp);
		(*head)->prev = 0;
		(*head)->numlen = numlen;
	}
	while ((*head)->next)
	{
		printf("addlen\n");
		indexsymbol(*head);
		(*head)->numlen = numlen++;
		(*head) = (*head)->next;
	}

}

