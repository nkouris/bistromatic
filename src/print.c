/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:52:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/14 04:53:38 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		printresult(t_list *list)
{
	char	*buf;
	int		numlen;
	int		i;

	numlen = list->numlen;
	i = 0;
printf("nummlen: %d\n", numlen);
	if (!(buf = ft_strnew((size_t)(numlen))))
		return (0);
	if (list->isneg)
		buf[i] = '-';
	while (i < numlen)
	{
//printf("%svalue: \t\t\t\t%c\nbase: %d\nkey: %s\nlist: %p\nprev: %p\nnext: %p\nnumlen: %d\nisneg: %d\n%s", GREEN, list->value, list->base, list->basekey, list, list->prev, list->next, list->numlen, list->isneg, NORMAL);
		printf("value: %c\n", list->value);
		buf[i++] = list->value;
		list->next ? (list = list->next) : list;
	//	printf("i: %d\nbuf: %s\n", i, buf);
	}
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	lstdel(&list);
	return (1);
}
