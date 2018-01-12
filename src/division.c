/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:41:42 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/12 15:30:01 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		rundiv(t_list **result, t_list **operand1, t_list **operand2, int max)
{
	int		passlen;
	int		op1len;
	t_list	*remainder;

	op1len = (*operand1)->numlen;
	// reverse operand1 && operand2, add element with na to end of operand2
	while ((*operand1)->prev)
		(*operand1) = (*operand1)->prev;
	if (!listhookup(operand2, 0, 1))
		return (0);
	while ((*operand2)->prev)
		(*operand2) = (*operand2)->prev;
	// snip sublist
	while (passlen < op1len)
	{
		// build sublist to pass to sendoperands in result
		snipdiv(remainder. operand1, operand2);
		findbottom(remainder, operand2);
		while (maxindex(remainder, operand2) == 1)
			snipdiv(remainder, operand1, operand2);
		{
			quotient++;

			sendoperands(remainder, '-', 0);
		sendoperands(remainder, '-', 0);
		compositediv(operand2, retemp);

}

void	snipdiv(t_list **remainder, t_list **operand1, t_list *operand2)
{
	t_list	*retemp;

	// find end of remainder
	retemp = (*remainder);
	if (!retemp)
	{
		retemp = *operand1;
		(*operand1) = (*operand1)->next;
		if (!listhookup(&retemp, 0, 1)
			return (0);
	}
	else
	{
		while (!(retemp->next)->na)
			retemp = retemp->next;
	// insert, in isolation, operand 1's next number, move operand 1 to next
		insertdiv(&retemp, operand1);
	}
}

int		insertdiv(t_list **retemp, t_list **operand1)
{
	t_list	*temp;
	t_list	*optemp;

	temp = (*retemp)->next;
	optemp = (*operand1)->next;
	(*operand1)->next = temp;
	(*retemp)->next = (*operand1);
	(*operand1) = optemp;
	return (1);
}

void	compositediv(t_list *operand2, t_list *retemp)
{
	while ((*retemp)->next)
		(*retemp) = (*retemp)->next;
	retemp->next = operand2;
	operand2->prev = retemp;
}

void	findbottom(t_list **remainder, t_list **operand2)
{
	if (remainder)
	{
		while ((*remainder1)->next)
			(*remainder) = (*remainder)->next;
	}
	if (operand2)
	{
		while ((*operand2)->next)
			(*operand2) = (*operand2)->next;
	}
}
