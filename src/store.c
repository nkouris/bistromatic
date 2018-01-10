/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:32:02 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/09 17:52:34 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		readandstore(char **argv, t_store **nlist)
{
	int		nin;
	char	*input_size;
	char	*input;

	nin = 0;
	if (!(input_size = (char *)ft_memalloc(sizeof(argv[2])))
		|| !(nin = ft_atoi(input_size))
		|| !(input = (char *)ft_memalloc(nin + 1))
		|| (read(0, input, nin) < 0))
		return (0);
	if (nin != (sizeof(argv[1]) - 1))
	{
		ft_putstr("syntax error");
		nin = 0;
	}
	if (argv[1] != "0123456789" && insize)
		!base_convert(&(argv[1]), sizeof(argv[1]), input, nlist) ? nin = 0: nin;
	if (!nin)
		return (0);
}

int		indexsymbol(char *basekey, size_t b, t_list *node)
{
	int i;

	i = 0;
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
