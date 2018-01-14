/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:52:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/13 22:58:03 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		printresult(t_list *list)
{
	char	*buf;
	int		numlen;
	int		i;

	list = list->prev;
	numlen = list->numlen;
	i = 0;
printf("nummlen: %d\n", numlen);
	if (!(buf = ft_strnew((size_t)(numlen))))
		return (0);
	if (list->isneg)
		buf[i] = '-';
	while (i++ < numlen)
	{
//printf("%sindex: \t\t\t\t%d\nbase: %d\nkey: %s\nlist: %p\nprev: %p\nnext: %p\nnumlen: %d\nisneg: %d\n%s", GREEN, list->symbolindex, list->base, list->basekey, list, list->prev, list->next, list->numlen, list->isneg, NORMAL);
	//	printf("value: %c\n", list->value);
		buf[numlen - i] = list->value;
		list->prev ? list = list->prev : list;
	//	printf("i: %d\nbuf: %s\n", i, buf);
	}
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	lstdel(&list);
	return (1);
}
