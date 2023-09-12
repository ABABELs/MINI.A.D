/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:21:55 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/12 18:04:00 by dilovancand      ###   ########.fr       */
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
char	**free_all(char **tab, int a)
{
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

int	ez_count(char *s, char flag, int a)
{
	a++;
	while (s[a] != flag)
		a++;
	a++;
	return (a);
}

/*
	compte le nombre de case à allouer dans le tableau
	ignore tout ce qui se trouve entre single ou double quote
*/
int	ft_count_tab(char *s, int a, int tab_nb)
{
	while (s[a])
	{
		while (s[a] && (s[a] == ' ' || s[a] == '\t'))
			a++;
		if (s[a] && (s[a] != ' ' || s[a] != '\t'))
		{
			while (s[a] && (s[a] != ' ' || s[a] != '\t'))
			{
				if ((s[a + 1] == ' ' || s[a + 1] == '\t') && s[a + 1]
					&& s[a] != '>' && s[a] != '<' && s[a] != '|')
					tab_nb++;
				else if (s[a] != ' ' && s[a] != '\t' && s[a] != '>'
					&& s[a] != '<' && s[a] && s[a] != '|'
					&& (s[a + 1] == '>' || s[a + 1] == '<'
						|| s[a + 1] == '|' || s[a + 1] == '\0'))
					tab_nb++;
				if (s[a] == 34 || s[a] == 39)
					a = ez_count (s, s[a], a);
				else
					a++;
			}
		}
	}
	return (tab_nb);
}
