/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:00:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/13 00:57:38 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

# define IS_OPER(x)		x == '-' || x == '+' || x == '*' || x == '/' || \
						x == '%' || x == '('

void	rpn2(char *str, int *i, t_list **start, t_operator **stack)
{
	if ((*stack) == NULL)
		push_stack(str[*i], stack);
	else
	{
		if (precedence(str[*i], (*stack)->op) > 0)
		{
//			printf("Precedence\n");
			push_stack(str[*i], stack);
		}
		else
		{
			while (precedence(str[*i], (*stack)->op) < 1)
			{
				pop_stack(start, stack);
				if ((*stack) == NULL)
					break ;

			}
			push_stack(str[*i], stack);
		}
	}
}


int		rpn(t_list **start, char *str, char *basekey)
{
	t_operator	*stack;
	int			i;
	
	i = 0;
	stack = NULL;
//	printf("FIND...\nstrPOS: %d numSYM: [%c] basekey: %s\n", i, str[i], basekey);
	while (str[i])
	{
		printf("RPN: str[%d]: [%c], basekey: %s\n", i, str[i], basekey);
		if ((ft_find(str[i], basekey) == 1) || (i > 0 && str[i] == '-' &&
		ft_find(str[i + 1], basekey) == 1 && ft_find(str[i - 1], "*/%(") == 1)
			|| (i == 0 && str[i] == '-' && ft_find(str[i + 1], basekey) == 1))
			add_list_node(str, i, start, basekey);
		else if (IS_OPER(str[i]))
			rpn2(str, &i, start, &stack);
		else if (str[i] == ')')
		{
			while (stack && stack->op != '(')
				pop_stack(start, &stack);
			free_stack_node(&stack);
			
		}
		else return (1);
		i++;
//	printf("base: %d\n", (*start)->base);
	}
	if (stack != NULL)
		pop_stack(start, &stack);
	printf("HERE2\n");
	return (0);
}
