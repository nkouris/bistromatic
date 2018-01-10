/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/09 18:19:33 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		remaindercalc(int result, int base)
{
	int	i;

	i = 1;
	while (base < result)
		base = base * i++;
	return (base - result);
}
