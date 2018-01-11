/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:26:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/10 22:05:30 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSM_H
# define BSM_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

/* FOR TESTING
*/
# include <stdio.h>
# define NORMAL		"\x1B[0m"
# define BLACK		"\x1B[30m"
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGNETA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"

typedef struct	s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			value;
	char			*basekey;
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

/* tools.c */
int		precedence(char op1, char op2);
void	solve_equation(char	op, t_list **start);

/* rpn.c */
int		rpn(char *str, t_list **start);

/* stack.c */
void	free_stack_node(t_operator **stack);
void	push_stack(char op, t_operator **stack);
void	pop_stack(t_list **start, t_operator **stack);

/* linked_list.c */
t_list	*add_na(t_list *previous, t_list **start);
void	add_list_node(char *str, int i, t_list **start);

#endif
