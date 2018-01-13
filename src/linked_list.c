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
	na->numlen = 0;
	na->base = previous->base;
	*start = na;
//	printf("%sADD NA:\nna->na = %d na->base = %d, prev->value = [%c]\n%s", CYAN, na->na, previous->base, previous->value, NORMAL);
	return (na);
}


void	add_list_node(char *str, int i, t_list **start, char *basekey)
{
	t_list	*ptr;
	t_list	*new;
	printf("ADD NODE!\n");
	ptr = *start;
	new = (t_list *)malloc(sizeof(t_list));
	new->na = false;
	new->value = str[i];
	new->basekey = basekey;
	
	
	
//	if (ptr != NULL && ptr->prev != NULL)
//		printf("%sBEGIN: node->value = %cn\n%s", GREEN, ptr->prev->value, NORMAL);
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
		new->numlen = (str[i] == '-') ? 0 : ptr->numlen + 1;
		new->base = ptr->base;
//		printf("send2 [%d] basekey [%s]\n", ptr->base, basekey);
	}
	else
	{
		*start = new;
		new->prev = NULL;
		new->numlen = (str[i] == '-') ? 0 : 1;
		new->base = ft_strlen(basekey);
//		printf("send2 [%d] basekey [%s]\n", new->base, basekey);
	}
	indexsymbol(new);
	new->next = ((ft_find(str[i + 1], basekey) != 1) || str[i + 1] == '\0') ?
	add_na(new, start) : NULL;
	

	//if you want to see how the final list is building, uncomment up to 73 line
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
	
	printf("%sONE NODE:\nstart->value: [%c]\nstart->numlen: [%d]\n%s", GREEN, \
		   new->value, new->numlen, NORMAL);
}
