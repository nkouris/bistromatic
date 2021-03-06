/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:15:08 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/14 23:49:18 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		main(int argc, char **argv)
{
	t_list	*new;
	char	*input_base[2];
	int		base;

	if (argc != 3)
		return (0);
	new = 0;
	base = 0;
	if (!(readandstore(argv, input_base, &base))
		|| (validation(&(input_base[0]), input_base[1]) != 0)
		|| !(rpn(&new, input_base[0], input_base[1])))
	{
		return (0);
	}
	printresult(new);
	return (1);
}

