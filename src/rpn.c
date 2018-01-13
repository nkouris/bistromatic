/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:20:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/09 13:20:27 by psprawka         ###   ########.fr       */
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
//		printf("HERE inside\n");
		if (precedence(str[*i], (*stack)->op) > 0)
			push_stack(str[*i], stack);
		else
		{
//			printf("HERE inside inside1\n");
			while (precedence(str[*i], (*stack)->op) < 1)
			{
				pop_stack(start, stack);
				if ((*stack) == NULL)
					break ;

			}
//			printf("HERE inside inside2\n");
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
	
	while (str[i])
	{
		printf("%d [%c], %s\n", i, str[i], basekey);
		if (ft_find(str[i], basekey) == 1)// ||
//			(str[i + 1] && ft_find(str[i + 1], basekey) == 1))
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
		printf("HERE1\n");
		i++;
//		while (stack != NULL && stack->prev != NULL)
//							stack = stack->prev;
//						printf("%sSTACK:\n", YELLOW);
//						if (stack != NULL)
//						{
//						printf("%c ", stack->op);
//						while (stack->next != NULL)
//						{
//							stack = stack->next;
//							printf("%c ", stack->op);
//						}
//						printf("\n%s", NORMAL);
//						}
//						else
//							printf("\n%s", NORMAL);
	}
	if (stack != NULL)
		pop_stack(start, &stack);
	printf("HERE2\n");
	return (0);
}

//int		main(int ac, char **av)
//{
//	t_list *start;
//	
//	start = NULL;
//	if (ac == 2)
//		printf("RETURNED VALUE:	%d\n", rpn(av[1], &start));
//	return (0);
//	
//}

