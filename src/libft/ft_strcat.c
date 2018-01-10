/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:52:56 by nkouris           #+#    #+#             */
/*   Updated: 2017/09/27 13:39:13 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *f_dst;

	f_dst = dst;
	dst += ft_strlen(dst);
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (f_dst);
}
