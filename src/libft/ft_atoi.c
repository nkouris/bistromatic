/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:37:30 by nkouris           #+#    #+#             */
/*   Updated: 2017/10/13 16:04:40 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int sign;
	int j;
	int i;

	sign = 1;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i = skip_spaces(str);
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			j = (j * 10) + (str[i] - 48);
			i++;
		}
		return (j * sign);
	}
	return (0);
}
