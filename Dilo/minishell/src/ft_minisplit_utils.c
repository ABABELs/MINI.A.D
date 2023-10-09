/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:21:55 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/09 13:50:48 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_sep(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else if (c == '>' || c == '<')
		return (2);
	else if (c == '|')
		return (3);
	return (0);
}

//free tout le tableau de chaine de caractère
char	**free_allin(char **tab, int a)
{
	if (!tab)
		return (NULL);
	while (0 <= a)
	{
		free(tab[a]);
		a--;
	}
	free(tab);
	return (NULL);
}

/*
	copie la chaine de caractère en partant du int 'letters', 
	le int 'd' represente la taille totale de la chaine de caractère
*/
void	cpy(char *tab, char *s, int letters, int d)
{
	int	a;

	a = 0;
	while (a < d)
	{
		tab[a] = s[a + letters];
		a++;
	}
	tab[a] = '\0';
}
