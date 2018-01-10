/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:15:08 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/09 19:41:18 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		main(int argc, char *argv)
{
	t_store	*nlist;

	if (argc != 3)
	{
		ft_putstr("usage: calc [base] [input_size]");
		return (0);
	}
	if (!(new = (t_store *)ft_memalloc(sizeof(t_store)))
		|| !(readandstore(argv, &new))
		|| !(operate(&new)))
		return (0);
	printresult(new);
}
