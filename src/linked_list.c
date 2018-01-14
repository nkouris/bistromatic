/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:36:27 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/13 18:14:36 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

t_list	*add_na(t_list *previous, t_list **start)
{
printf("%sAdd na\n", YELLOW);
	t_list	*na;
	
	na = (t_list *)ft_memalloc(sizeof(t_list));
	na->next = NULL;
	na->prev = previous;
	na->na = true;
	na->value = '\0';
	na->numlen = previous->numlen;
	na->base = previous->base;
	*start = na;
	printf("NA: %p\nPrev: %p\nNext: %p\n%s", na, na->prev, na->next, NORMAL);
	return (na);
}


void	add_list_node(char *str, int i, t_list **start, char *basekey)
{
	t_list	*ptr;
	t_list	*new;
	printf("ADD NODE, str[i] = %c!\n", str[i]);
	ptr = *start;
	new = (t_list *)ft_memalloc(sizeof(t_list));
	new->na = false;
	new->value = str[i];
	new->basekey = basekey;
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
		new->numlen = (str[i] == '-') ? 0 : ptr->numlen + 1;
		new->base = ptr->base;
	}
	else
	{
		*start = new;
		new->prev = 0;
		new->numlen = (str[i] == '-') ? 0 : 1;
		new->base = ft_strlen(basekey);
	}
	indexsymbol(new);

	new->next = ((ft_find(str[i + 1], basekey) != 1) || str[i + 1] == '\0') ?
	add_na(new, start) : NULL;
	printf("%sONE NODE:\nindex: [%d]\nnew: %p\nnew->prev: %p\nnew->next: %p\nnew->value: %c\n%s", GREEN, new->symbolindex, new, new->prev, new->next, new->value, NORMAL);
}

