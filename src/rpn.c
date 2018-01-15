/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:00:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/01/14 19:11:52 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

# define IS_OPER(x)		x == '-' || x == '+' || x == '*' || x == '/' || \
						x == '%' || x == '('

void		rpn2(char *str, int *i, t_list **head, t_operator **stack)
{
	if ((*stack) == NULL)
		push_stack(str[*i], stack);
	else
	{
		if (precedence(str[*i], (*stack)->op) > 0)
		{
		printf("rpn2 pop\n");
			push_stack(str[*i], stack);
		}
		else
		{
			while (precedence(str[*i], (*stack)->op) < 1)
			{
				pop_stack(head, stack);
				if ((*stack) == NULL)
					break ;

			}
			push_stack(str[*i], stack);
		}
	}
}


int		rpn(t_list **head, char *str, char *basekey)
{
	t_operator	*stack;
	int			i;
	
	i = 0;
	stack = NULL;
	while (str[i])
	{
//printf("RPN: str[%d]: [%c], basekey: %s\n", i, str[i], basekey);
		if ((ft_find(str[i], basekey) == 1) || (i > 0 && str[i] == '-' &&
		ft_find(str[i + 1], basekey) == 1 && ft_find(str[i - 1], "*/%(") == 1)
			|| (i == 0 && str[i] == '-' && ft_find(str[i + 1], basekey) == 1))
			add_list_node(str, i, head, basekey);
		else if (IS_OPER(str[i]))
			rpn2(str, &i, head, &stack);
		else if (str[i] == ')')
		{
			while (stack && stack->op != '(')
				pop_stack(head, &stack);
			free_stack_node(&stack);
		}
		else return (0);
		i++;
//printf("HEAD: %p\n", (*head));
	}
	while (stack != NULL)
		pop_stack(head, &stack);
//	printf("HERE2\n");
	return (1);
}
