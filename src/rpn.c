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


/*
**	Function precedence returns
**	->	negative number when the last operator on a stack is more important
**		than a str[i]'s operator;
**	->	zero when the last operator on a stack has the same importance like
**		a str[i]'s operator;
**	->	positive number when is possible to push a str[i]'s operator on the
**		top of a stack;
*/


int		precedence(char op1, char op2, int *bracket)
{
	printf("%sIM IN PRECEDENCE: op1 %c, op2 %c\n%s", MAGNETA, op1, op2, NORMAL);
	if (op1 == '-' || op1 == '+')
		op1 = '1';
	else if (op1 == '*' || op1 == '/' || op1 == '%')
		op1 = '2';
	else if (op1 == '(')
	{
		op1 = '3';
		*bracket = 1;
	}
	
	if (op2 == '(')
		op2 = '0';
	else if (op2 == '-' || op2 == '+')
		op2 = '1';
	else if (op2 == '*' || op2 == '/' || op2 == '%')
		op2 = '2';
	
	printf("%sPRECEDENCE: %d\n%s", MAGNETA, (int)(op1 - op2), NORMAL);
	return((int)(op1 - op2));
}

t_list	*add_na(t_list *previous, t_list **start)
{
	t_list	*na;
	
	na = (t_list *)malloc(sizeof(t_list));
	na->next = NULL;
	na->prev = previous;
	na->na = true;
	na->value = '\0';
	*start = na;
	printf("%sADD NA:\nna->na = %d\n%s", CYAN, na->na, NORMAL);
	return (na);
}


void	add_list_node(char *str, int i, t_list **start)
{
	t_list	*ptr;
	t_list	*new;
	
	ptr = *start;
	new = (t_list *)malloc(sizeof(t_list));
	new->next = ((str[i + 1]) && !(str[i + 1] > 47 && str[i + 1] < 58)) ?
			add_na(new, start): NULL;
	new->na = false;
	if (ptr != NULL && ptr->prev != NULL)
		printf("%sBEGIN: node->value = %cn\n%s", GREEN, ptr->prev->value, NORMAL);
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
	new->value = str[i];
	printf("%sADD LIST NODE:\nnode->value = %c\n%s", GREEN, new->value, NORMAL);
}

void	push_stack(char op, t_operator **stack)
{
	t_operator	*sign;
	t_operator	*head;

	head = *stack;
	sign = (t_operator *)malloc(sizeof(t_operator));
	sign->next = NULL;
	sign->op = op;
	if (head != NULL)
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = sign;
		sign->prev = *stack;
	}
	else
		sign->prev = NULL;
	*stack = sign;
	
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	printf("%sSTACK:\n", YELLOW);
	printf("%c ", (*stack)->op);
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		printf("%c ", (*stack)->op);
	}
	printf("\n%s", NORMAL);
	*stack = sign;
}

void	free_stack_node(t_operator **stack)
{
	t_operator *temp;
	
	temp = *stack;
	*stack = (*stack)->prev;
	free(temp);
	if ((*stack) != NULL)
	{
		(*stack)->next = NULL;
		printf("%sIM IN FREE: stack's pointing at: %c\n%s", BLUE, (*stack)->op, NORMAL);
	}
	printf("HERE I AM\n");
}

void	pop_stack(t_list **start, t_operator **stack)
{
	t_operator *head;

	head = *stack;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	printf("I'M IN POP_STACK! start->op: %c\n", (*stack)->op);
	solve_equation((*stack)->op, start);
	printf("I'M IN POP_STACK!2\n");
	free_stack_node(stack);
	printf("I'M IN POP_STACK!3\n");
}



# define IS_OPER(x)			x == '-' || x == '+' || x == '*' || x == '/' || \
							x == '%' || x == '('
# define IS_NUMBER(x, x1)	(x == '-' && x1 && x1 > 47 && x1 < 58) || \
							(x > 47 && x < 58)


int		rpn(char *str, t_list **start)
{
	t_operator	*stack;
	int			i;
	int			bracket;
	
	i = 0;
	bracket = 0;
	stack = NULL;
	
	while (str[i])
	{
		printf("HERE i = %d str[i] = %c\n", i, str[i]);
		if (IS_NUMBER(str[i], str[i + 1]))
			add_list_node(str, i, start);
		else if (IS_OPER(str[i]))
		{
			if (stack == NULL)
				push_stack(str[i], &stack);
			else
			{
				printf("HERE inside\n");
				if (precedence(str[i], stack->op, &bracket) > 0)
					push_stack(str[i], &stack);
				else
				{
					printf("HERE inside inside1\n");
					while (precedence(str[i], stack->op, &bracket) < 1)
					{
						pop_stack(start, &stack);
						
						if (stack == NULL)
							break ;
						
						
						t_operator *head;
						head = stack;
						while (stack->prev != NULL)
							stack = stack->prev;
						printf("%sSTACK:\n", YELLOW);
						printf("%c ", stack->op);
						while (stack->next != NULL)
						{
							stack = stack->next;
							printf("%c ", stack->op);
						}
						printf("\n%s", NORMAL);
							stack = head;
					}
					printf("HERE inside inside2\n");
					push_stack(str[i], &stack);
				}
			}
		}
		else if (str[i] == ')')
		{
			while (stack && stack->op != '(')
			{
				solve_equation(stack->op, start);
				free_stack_node(&stack);
				
			}
			free_stack_node(&stack);
			
			while (stack != NULL && stack->prev != NULL)
				stack = stack->prev;
			printf("%sSTACK:\n", YELLOW);
			if (stack != NULL)
			{
			printf("%c ", stack->op);
			while (stack->next != NULL)
			{
				stack = stack->next;
				printf("%c ", stack->op);
			}
			printf("\n%s", NORMAL);
			}
			else
				printf("\n%s", NORMAL);
				
			
		}
		else if (str[i] == ' ')
			;
		else return (1);
		i++;
	}
	if (stack != NULL)
	{
		solve_equation(stack->op, start);
		free_stack_node(&stack);
	}

	return (0);
}

int		main(int ac, char **av)
{
	t_list *start;
	
	start = NULL;
	if (ac == 2)
		printf("RETURNED VALUE:	%d\n", rpn(av[1], &start));
	return (0);
	
}
