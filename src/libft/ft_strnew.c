/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:52:12 by nkouris           #+#    #+#             */
/*   Updated: 2017/11/01 14:34:50 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *bloc;

	size = size + 1;
	bloc = (char*)ft_memalloc(sizeof(char) * size);
	if (!bloc)
		return (0);
	return (bloc);
}
