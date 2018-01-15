/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:25:24 by psprawka          #+#    #+#             */
/*   Updated: 2018/01/14 15:55:21 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsm.h"

int		remove_floats(char **head, char *base, int i, int j)
{
	char	*new, *str;
	int		brackets = 0;
	int		res = 0;
	
	new = (char	*)malloc(ft_strlen(*head) * 2);
	str = *head;
	//	printf("inside remove floats\n");
	while (str[i])
	{
		if ((i == 0 && str[i] == '-' && str[i + 1] == 40) || \
			(str[i - 1] == 40 && str[i] == '-' && str[i + 1] == 40))
		{
			//			printf("inside if statement\n");
			res = 1;
			//			printf("inside if statement str[%d] = %c\n", i, str[i]);
			i++;
			new[j++] = str[i++];
			if (str[i] == 40)
				new[j++] = '-';
			
			while (str[i] != 41 && str[i] != '\0') //while were on the same level so while we hit a right
			{
				//				printf("%s1inside huge while loop, i = %d, str[i] = %c%s\n",CYAN, i, str[i], NORMAL);
				if (str[i] == 40)
				{
					//					printf("IM HERE\n");
					brackets++;
					new[j++] = str[i++];
					while (brackets != 0 && str[i] != '\0' )
					{
						str[i] == 40 ? brackets++ : brackets;
						str[i] == 41 ? brackets-- : brackets;
						//						printf("%sstr[%d] = %c, brackets = %d\n%s", GREEN, i, str[i], brackets, NORMAL);
						new[j++] = str[i++];
					}
				}
				//				printf("%s2inside huge while loop, i = %d, str[i] = %c%s\n",CYAN, i, str[i], NORMAL);
				//				printf("%sAFTER LOOP, str[%d] = %c%s\n", RED, i, str[i], NORMAL);
				if (str[i] == '-')
				{
					new[j++] = '+';
					i++;
					//					printf("%sstr[%d] = %c%s\n", RED, i, str[i], NORMAL);
				}
				else if ((ft_find(str[i], base) == 1 || str[i] == '+'))
				{
					str[i] == '+' ? i++ : i;
					new[j++] = '-';
				}
				while ((ft_find(str[i], base) == 1 || ft_find(str[i], "*/%") == 1) && str[i] != 41)
					new[j++] = str[i++];
			}
		}
		if ((i == 0 && str[i] == '+' && str[i + 1] == 40) || \
			(str[i - 1] == 40 && str[i] == '+' && str[i + 1] == 40))
			i++;
		new[j++] = str[i++];
	}
	new[j++] = '\0';
	free(*head);
	*head = new;
	return (res);
}
