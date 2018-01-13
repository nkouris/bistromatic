/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:52:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/11 09:52:50 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

void	printresult(t_list *list)
{
	t_list *start;

	start = list;
	while (list != NULL)
	{
		if (list->na == false)
			write(1, &(list->value), 1);
		list = list->next;
	}
	list = start;
}
