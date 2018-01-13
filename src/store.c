/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:32:02 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/10 21:45:17 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		readandstore(char **argv, char **input_base, int *base)
{
	int		ninput;
	int		nstrbasekey;
	int		nstrinput;
	char	*input_size;
	char	*input;

	if (!(nstrbasekey = (int)ft_strlen((const char *)argv[1]))
		|| !(nstrinput = (int)ft_strlen((const char *)argv[2]))
		|| !(input_size = (char *)ft_strnew((size_t)nstrinput))
		|| !(ninput = ft_atoi(input_size))
		|| !(input = (char *)ft_strnew((size_t)ninput))
		|| (read(0, input, (size_t)ninput) < 0)
		|| !(input_size = (char *)ft_strnew((size_t)nstrbasekey))
		|| !(ft_strcpy(input_size, (const char *)(argv[1]))))
		return (0);
	*base = nstrbasekey;
	input_base[0] = input;
	input_base[1] = input_size;
	return (1);
}

int		indexsymbol(int b, t_list *node)
{
	int		i;
	char	*basekey;

	i = 0;
	basekey = node->basekey;
	while (*basekey != node->value && i++ < b)
		basekey++;
	if (i > b)
	{
		ft_putstr("syntax error");
		return (0);
	}
	node->base = b;
	node->symbolindex = i;
	return (1);
}
