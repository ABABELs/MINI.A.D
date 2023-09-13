/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:28:59 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/13 11:22:54 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//malloc et remplie la chaine de caractère 
static int	no_quote(char **tab, char *s, int letters)
{
	int		d;
	char	quote;

	d = 0;
	while (is_sep(s[letters + d]) == 0 && s[letters + d])
	{
		if (s[letters + d] == 34 || s[letters + d] == 39)
		{
			quote = s[letters + d];
			d++;
			while (s[letters + d] != quote)
				d++;
			d++;
		}
		else
			d++;
	}
	*tab = malloc(sizeof(char) * (d + 1));
	if (*tab == 0)
		return (-1);
	cpy(*tab, (char *)s, letters, d);
	return (d);
}

static int	ft_redirjsp(char **tab, char *s, int letters)
{
	int	a;

	a = 0;
	if (is_sep(s[letters + a]) == 2 && s[letters + a])
	{
		while (is_sep(s[letters + a]) == 2 && s[letters + a])
		a++;
	}
	else if (is_sep(s[letters + a]) == 3 && s[letters + a])
	{
		while (is_sep(s[letters + a]) == 3 && s[letters + a])
		a++;
	}
	if (a > 2)
		return (-1);
	*tab = malloc(sizeof(char) * (a + 1));
	if (*tab == 0)
		return (-1);
	cpy(*tab, (char *)s, letters, a);
	return (a);
}

/*
	remplie le tableau de chaine de caractère avant de le renvoyer
*/
static char	**into_tab(char **tab, char const *s, int letters)
{
	int	b;
	int	d;

	b = 0;
	while (s[letters])
	{
		d = 0;
		if (is_sep(s[letters]) == 0)
			d = no_quote(&tab[b++], (char *)s, letters);
		else if (is_sep(s[letters]) == 2)
			d = ft_redirjsp(&tab[b++], (char *)s, letters);
		else if (is_sep(s[letters]) == 3)
			d = ft_redirjsp(&tab[b++], (char *)s, letters);
		else
			letters++;
		if (d != 0)
		{
			if (d == -1)
				return (free_all(tab, (b - 1)));
			letters = letters + d;
		}
	}
	tab[b] = 0;
	return (tab);
}

//un split qui ignore les espaces à l'intérieur d'une single ou double quote
char	**ft_minisplit(char const *s)
{
	int		tab_nb;
	int		real_tab;
	char	**tab;
	int		a;

	tab_nb = 0;
	real_tab = 0;
	a = 0;
	if (!s)
		return (NULL);
	real_tab = ft_count_tab((char *)s, a, tab_nb);
	real_tab = ft_redir_count((char *)s, '|', a, tab_nb) + real_tab;
	real_tab = ft_redir_count((char *)s, '<', a, tab_nb) + (real_tab);
	real_tab = ft_redir_count((char *)s, '>', a, tab_nb) + (real_tab);
	tab = malloc(sizeof(char *) * (real_tab + 1));
	if (tab == 0)
		return (NULL);
	return (into_tab(tab, s, tab_nb));
}