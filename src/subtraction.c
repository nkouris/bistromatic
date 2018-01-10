/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:07:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/10 14:37:04 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		subtraction(t_list **head)
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
	if (operand1->numlen > operand2->numlen && operand1->isneg)
	{
		operand2->isneg = 1;
		runadd
}

void	subnegtrack(t_list *operand1, t_list *operand2, t_list **result)
{
	if (operand1->nunmlen > operand2->numlen)
	{
		if (operand1->isneg && !operand2->isneg)
			operand2->isneg = 1;
		else if (operand1->isneg && operand2->isneg)
			operand2->isneg = 0;
		runadd(result, operand1, operand2);
	}
	if (operand2->numlen > operand1->numlen)
	{
		if (operand2->isneg && !operand1->isneg)
			operand1->isneg = 1;
		else if (operand2->isneg && operand1->isneg)
			operand1->isneg = 0;
		runadd(result, operand2, operand1);
	}
}
