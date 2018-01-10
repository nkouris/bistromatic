/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:19:10 by nkouris           #+#    #+#             */
/*   Updated: 2017/09/29 00:39:24 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		delim_count(char const *orig, char delim)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (orig[i] != '\0')
	{
		if (orig[i] != delim && (orig[i + 1] == delim || orig[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char		**delim_split(char **a, char const *b, char c)
{
	int				i;
	unsigned int	t_len;

	i = 0;
	while (*b)
	{
		if (*b == c)
			b++;
		else
		{
			t_len = 0;
			while (b[t_len] != c && b[t_len] != '\0')
				t_len++;
			a[i] = ft_strsub(b, 0, t_len);
			i++;
			b += t_len;
		}
	}
	return (a);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	char	**result;

	if (s == 0)
		return (0);
	j = delim_count(s, c);
	result = (char **)ft_memalloc(sizeof(char *) * (j + 1));
	result[j] = 0;
	if (!result)
		return (0);
	else
		result = delim_split(result, s, c);
	return (result);
}
