/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:36:27 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/10 15:36:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

t_list	*add_na(t_list *previous, t_list **start)
{
	t_list	*na;
	
	na = (t_list *)malloc(sizeof(t_list));
	na->next = NULL;
	na->prev = previous;
	na->na = true;
	na->value = '\0';
	*start = na;
//	printf("%sADD NA:\nna->na = %d\n%s", CYAN, na->na, NORMAL);
	return (na);
}


void	add_list_node(char *str, int i, t_list **start)
{
	t_list	*ptr;
	t_list	*new;
	
	ptr = *start;
	new = (t_list *)malloc(sizeof(t_list));
	new->next = ((str[i + 1]) && !(str[i + 1] > 47 && str[i + 1] < 58)) ?
	add_na(new, start): NULL;
	new->na = false;
	new->value = str[i];
//	if (ptr != NULL && ptr->prev != NULL)
//		printf("%sBEGIN: node->value = %cn\n%s", GREEN, ptr->prev->value, NORMAL);
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	else
	{
		*start = new;
		new->prev = NULL;
	}

//	//if you want to see how the final list is building, uncomment up to 73 line
//	if ((*start) != NULL)
//	{
//		if ((*start)->value != '\0')
//		{
//			printf("%sSTART:\n", CYAN);
//			printf("%c ", (*start)->value);
//		}
//		while ((*start)->next != NULL)
//		{
//			*start = (*start)->next;
//			printf("%c ", (*start)->value);
//			if ((*start)->next == NULL)
//				printf("\n%s", NORMAL);
//		}
//		while ((*start)->prev != NULL)
//			*start = (*start)->prev;
//	}
}
