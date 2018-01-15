/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:36:27 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/14 19:31:46 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		add_na(t_list *new)
{
printf("%sAddNa\n", YELLOW);
	t_list	*na;
	
	if (!(na = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	na->next = NULL;
	na->prev = new;
	na->na = true;
	na->value = '\0';
	na->basekey = new->basekey;
	na->numlen = new->numlen;
	na->base = new->base;
	new->next = na;
printf("NA: %p\nPrev: %p\nNext: %p\n%s", na, na->prev, na->next, NORMAL);
	return (1);
}

int		add_list_node(char *str, int i, t_list **head, char *basekey)
{
printf("ADD NODE, str[i] = %c!\n", str[i]);
	t_list	*new;

	t_list *temp;
	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	new->na = false;
	new->value = str[i];
	new->basekey = basekey;
//printf("Head@ start %p\n", (*head));
	if (!(*head))
	{
//printf("NEW\n");
		*head = new;
		new->numlen = ((str[i] == '-') ? 0 : 1);
		new->base = ft_strlen(basekey);
	}
	else
	{
		temp = (*head);
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
//	printf("temp->na: %d\n", temp->na);
		if (str[i] == '-')
			new->numlen = 0;
		else if (temp->na)
			new->numlen = 1;
		else
			new->numlen = temp->numlen + 1;
	//	temp->na ? (new->numlen = 1) : (new->numlen);
	//	str[i] = '-' ? (new->numlen = 0) : (new->numlen);
	//	(!temp->na && str[i] != '-') ? (new->numlen = temp->numlen + 1) : (new->numlen);
		new->base = temp->base;
	}
	indexsymbol(new);

printf("%sONE NODE:\nindex: [%d]\nnew: %p\nnew->prev: %p\nnew->next: %p\nnew->value: %c\nnew->numlen: %d\n%s", GREEN, new->symbolindex, new, new->prev, new->next, new->value, new->numlen, NORMAL);

	return (((ft_find(str[i + 1], basekey) != 1) || str[i + 1] == '\0') ?
	add_na(new) : 0);
}

