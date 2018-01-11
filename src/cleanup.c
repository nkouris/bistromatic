/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:26:19 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/10 16:43:29 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lstdel(t_list *start)
{
	t_list *temp;

	if (*((*start)->basekey))
		free((void *)((*start)->basekey));
	if ((*start)->next)
	{
		while ((*start))
		{
			temp = (*start)->next;
			free((void *)(*start));
			(*start) = temp;
		}
	}
	else
	{
		while ((*start))
		{
			temp = (*start)->prev;
			free((void *)(*start));
			(*start) = temp;
		}
	}
}
