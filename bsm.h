/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:26:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/08 22:53:24 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSM_H
# define BSM_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "inc/libft.h"
# include <stdbool.h>

typedef struct	s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			value;
	bool			if_NA;
}				t_list;

typedef struct	s_operator
{
	struct s_operator	*next;
	struct s_operator	*prev;
	char				op;
}				t_operator;


/* start.c */
int		main(int argc, char **argv);

/* store.c */
int		readandstore(char **argv, t_store **nlist);
int		base_convert(char **basestr, size_t b);

#endif
