/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:26:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/13 20:02:32 by nkouris          ###   ########.fr       */
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
int		readandstore(char **argv, char **input_base, int *base);
int		indexsymbol(t_list *node);

/* addition.c */
void	addremainder(t_list **result, int add, int base);
int		runadd(t_list **result, t_list *top, t_list *bottom);
int		addtrack(t_list **result, t_list *operand1, t_list *operand2, int max);

/* subtraction.c */
int		runsub(t_list **result, t_list *top, t_list *bottom);
int		subtrack(t_list **result, t_list *operand1, t_list *operand2, int max);

/* multiplication.c */
void	mulremainder(t_list **result, int mul, int base);
int		mulmagpush(t_list **result, int addlevel);
int		runmul(t_list **result, t_list *top, t_list *bottom);
int		multrack(t_list **result, t_list *operand1, t_list *operand2, int max);

/* division.c */
void	findbottom(t_list **remainder, t_list **operand2);
void	compositediv(t_list *operand2, t_list *retemp);
int		insertdiv(t_list **retemp, t_list **operand1);
void	snipdiv(t_list **remainder, t_list **operand1, t_list *operand2);
int		rundiv(t_list **result, t_list **operand1, t_list **operand2, int max);

/* operations.c */
int		operandsplit(t_list **head, t_list **operand1, t_list **operand2);
int		maxindex(t_list **operand1, t_list **operand2, char op);
int		sendoperands(t_list **head, char op, bool delhead);
int		listhookup(t_list **node, bool prev, bool na);
t_list	*sym_lst(t_list *temp);
void	append(t_list **head);

/* tools.c */
int		precedence(char op1, char op2);
int		ft_find(char c, char *base);

/* rpn.c */
int		rpn(t_list **start, char *str, char *basekey);

/* stack.c */
void	free_stack_node(t_operator **stack);
void	push_stack(char op, t_operator **stack);
void	pop_stack(t_list **start, t_operator **stack);

/* linked_list.c */
t_list	*add_na(t_list *previous, t_list **start);
void	add_list_node(char *str, int i, t_list **start, char *basekey);

/* print.c */
int		printresult(t_list *list);

/* validation.c */
int		validation(char **head, char *base);

/* parsing.c */
int	remove_floats(char **head, char *base, int i, int j);

/* cleanup.c */
int		lstdel(t_list **start);

#endif
