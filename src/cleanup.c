/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:26:19 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/12 23:19:11 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		lstdel(t_list **start)
{
	t_list *temp;

//	if (*((*start)->basekey))
//		free((void *)((*start)->basekey));
	if ((*start)->next)
	{
		while ((*start))
		{
			temp = (*start)->next;
			free(*start);
			(*start) = temp;
		}
	}
	else
	{
		while ((*start))
		{
			temp = (*start)->prev;
			free(*start);
			(*start) = temp;
		}
	}
	return (1);
}
