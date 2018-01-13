/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/12 15:29:56 by nkouris          ###   ########.fr       */
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
		|| !(listhookup(&result, 0, 1)))
		return (0);
//	printf("send inside1\n");
	operandsplit(head, &operand1, &operand2);
//	printf("send inside2\n");
	max = maxindex(&operand1, &operand2, op);
//	printf("send inside3\n");
	op =='+' ? error = addtrack(&result, operand1, operand2, max) : error;
//	printf("send inside3.0\n");
	op == '-' ? error = subtrack(&result, operand1, operand2, max) : error;
//	printf("send inside3.1\n");
	op == '*' ? error = multrack(&result, operand1, operand2, max) : error;
//	op = '/' ? error = rundiv(&result, &operand1, &operand2, max) : error;
//	op = '%' ? error = rundiv(&result, &operand1, &operand2, max) : error;
	// delhead to protect recursion of division head, which is a composite of
	// the divisor and temporary dividend
// wrap lstdel with return value
//	printf("send inside4\n");
	delhead ? error = lstdel(head) : error;
//	printf("send inside5\n");
//	lstdel(&operand1);
//	printf("send inside6\n");
//	lstdel(&operand2);
//	printf("send inside7\n");
	(*head) = result;
	append(head);
//	printf("head address: %p\n", *head);
//	if ((*head) != NULL)
//	{
//		printf("[%d] ", (*head)->next->symbolindex);
//		if ((*head)->symbolindex != '\0')
//		{
//			printf("%sSTART:\n", CYAN);
//			printf("%c ", (*head)->next->symbolindex);
//		}
//		while ((*head)->next != NULL)
//		{
//			*head = (*head)->next;
//			printf("%d", (*head)->symbolindex);
//			if ((*head)->next == NULL)
//				printf("\n%s", NORMAL);
//		}
//		while ((*head)->prev != NULL)
//			*head = (*head)->prev;
//	}
// fill node->value with index value corresponding symbol
	return (error);
}

int		operandsplit(t_list **head, t_list **operand1, t_list **operand2)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (!(*operand2))
	{
		temp = (*head);
//		printf("HEAD %p previous %p next %p %d\n", (*head), (*head)->prev, (*head)->next, (*head)->symbolindex);
//		printf("negative check\n");
		temp->prev = 0;
//		printf("negative check\n");
		if (temp->value == '-')
		{
			i = 1;
			temp = temp->next;
			ft_memdel((void **)&(*head));
		}
//		printf("funrther\n");
		while (!(temp->na))
		{
			if (i)
				temp->isneg = 1;
//			printf("TEMP previous %p, next %p, %c\n", temp->prev, temp->next, temp->value);
			temp = temp->next;
		}
//		printf("funrther1.1\n");
		if (temp->next)
			(*head) = temp->next;
//		printf("funrther2\n");
//		printf("previous %p net %p", temp->prev, temp->next);
		(!(*operand1)) ? ((*operand1) = sym_lst(temp))
		: ((*operand2) = sym_lst(temp));
//		printf("%s%c, %p\n", YELLOW, (*operand1)->value, (*operand1)->next);
//		if (*operand2)
//			printf("%c, %p\n%s", (*operand2)->value, (*operand2)->next, NORMAL);
//		printf("%p\n", (*head));
//		printf("funrther2.0\n");
		
	}
//	printf("funrther3\n");
	return (1);
}

t_list	*sym_lst(t_list *temp)
{
	t_list *op_lo;
//	printf("symlist1\n");
	op_lo = temp->prev;
//	printf("symlist2\n");
	free(temp);
//	printf("symlist3\n");
	op_lo->next = 0;
//	printf("symlist4\n");
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
	}
	else
	{
		if (!((*node)->prev = ft_memalloc(sizeof(t_list))))
			return (0);
		((*node)->prev)->next = (*node);
	}
	return (1);
}

void	append(t_list **head)
{
	t_list *temp;
	
	temp = (*head);
	if ((*head)->isneg)
		(*head)->value = '-';
	else
	{
		(*head) = (*head)->next;
		free(temp);
	}
	while ((*head)->next)
		(*head) = (*head)->next;
}

