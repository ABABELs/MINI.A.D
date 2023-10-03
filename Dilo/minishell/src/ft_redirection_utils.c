/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:50:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/03 14:39:58 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] == s2[a]) && (s1[a] != '\0'))
		a++;
	if (s1[a] == '\0' && s2[a] == '\0')
		return (0);
	return (1);
}

//compte le nombre de pipe qu'il y a dans l'input et malloc un tableau de int
int	ft_pipecount(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] == '|')
		{
			while (str[a] == '|')
				a++;
			b++;
		}
		a++;
	}
	return (b);
}
