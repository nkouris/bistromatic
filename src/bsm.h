/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:26:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/10 12:17:21 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSM_H
# define BSM_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>

/* FOR TESTING
*/
# include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			value;
	bool			na;
	bool			isneg;
	int				symbolindex;
	int				remainder;
	int				numlen;
	int				base;
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
int		readandstore(char **argv, t_list **nlist);
int		indexsymbol(char *basekey, int b, t_list *node);

/* addition.c */
int		addition(t_list **head);
int		runadd(t_list **result, t_list *top, t_list *bottom);
void	addremainder(t_list **result, int add, int base);

/* operations.c */
int		operandsplit(t_list **head, t_list **operand1, t_list **operand2);
t_list	*sym_lst(t_list *temp);
int		operandlen(t_list **operand1, t_list **operand2);
int		remaindercalc(int result, int base);

#endif
