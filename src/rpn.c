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
# include <stdlib.h>

/*
**	Function precedence returns
**	->	negative number when the last operator on a stack is more important
**		than a str[i]'s operator;
**	->	zero when the last operator on a stack has the same importance like
**		a str[i]'s operator;
**	->	positive number when is possible to push a str[i]'s operator on the
**		top of a stack;
*/


void	solve_equation(char	op, t_list **start)
{
	if (op == '+')
		addition(start);
	if (op == '%')
		modulo(start);
	if (op == '/')
		division(start);
	if (op == '*')
		multiplication(start);
	if (op == '-')
		substraction(start);
}

int		precedence(char op1, char op2)
{
	if (op1 == '-' || op1 == '+')
		op1 = '1';
	else if (op1 == '*' || op1 == '/' || op1 == '%')
		op1 = '2';
	else if (op1 == '(')
		op1 = '3';
	
	if (op2 == '(')
		op2 = '0';
	else if (op2 == '-' || op2 == '+')
		op2 = '1';
	else if (op2 == '*' || op2 == '/' || op2 == '%')
		op2 = '2';
	
	return(int(op1 - op2));
}

t_list	*add_na(t_list *previous)
{
	t_list	*na;
	
	na = (t_list *)malloc(sizeof(t_list));
	na->next = NULL;
	na->prev = previous;
	na->na = true;
	na->value = '\0';
	
	return (na);
}


void	add_list_node(char *str, int i, t_list **start)
{
	t_list	*ptr;
	t_list	*new;
	
	ptr = *start;
	new = (t_list *)malloc(sizeof(t_list));
	new->next = ((str[i + 1]) && !(str[i + 1] > 47 && str[i + 1] < 58)) ?
			add_na(new): NULL;
	new->na = false;
	
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	else
	{
		*start = new;
		new->prev = NULL;
	}
}

void	push_stack(char op, t_operator *stack)
{
	t_operator	*sign;
	t_operator	*head;
	
	head = stack;
	sign = (t_operator *)malloc(sizeof(t_operator));
	sign->next = NULL;
	sign->op = op;
	if (head != NULL)
	{
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = sign;
		sign->prev = stack;
		stack = head
	}
	else
	{
		sign->prev = NULL;
		stack = sign;
	}
}

void	pop_stack(t_list **start, t_operator **stack)
{
	solve_equation(stack->op, start);
	free_stack_node(stack);
}

void	free_stack_node(t_operator **stack)
{
	t_operator *temp;
	
	temp = *stack;
	*stack = *stack->prev
	free(*temp);
	*stack->next = NULL;
}

# define IS_OPER(x)			x == '-' || x == '+' || x == '*' || x == '/' || \
							x == '%' || x == '('
# define IS_NUMBER(x, x1)	(x == '-' && x1 && x1 > 47 && x1 < 58) || \
							(x > 47 && x < 58)


int		rpn(char *str, t_list **start)
{
	t_operator	*stack;
	int			i;
	
	i = 0;
	stack = NULL;
	
	while (str[i])
	{
		if (IS_NUMBER(str[i], str[i + 1]))
			add_list_node(str, i, start);
		else if (IS_OPER(str[i]))
		{
			if (stack == NULL)
				push_stack(str[i], NULL);
			else
			{
				if (precedence(str[i], stack->op) > 0)
					push_stack(str[i], &stack);
				else
				{
					while (precedence(str[i], stack->op) <= 1)
						pop_stack(start, &stack);
					solve_equation(str[i], start);
				}
			}
		}
		else if (str[i] == ')')
		{
			while (stack->op != '(')	//pop_stack(start, stack);
			{
				solve_equation(stack->op, start);
				free_stack_node(&stack);
			}
			free_stack_node(&stack);
		}
		else return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_list *start;
	
	start = NULL;
	printf("RETURNED VALUE:	%d\n", rpn(av[1], &start));
	return (0);
	
}
