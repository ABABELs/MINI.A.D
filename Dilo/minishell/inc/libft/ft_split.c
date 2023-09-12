/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:32:41 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/08 14:32:41 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	issep(char str, char sep)
{
	if (str == sep)
		return (1);
	return (0);
}

static void	cpy(char *tab, char *s, int letters, int d)
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

static char	**free_all(char **tab, int a)
{
	while (0 <= a)
	{
		free(tab[a]);
		a--;
	}
	free(tab);
	return (NULL);
}

static char	**into_tab(char **tab, char const *s, char c)
{
	int	letters;
	int	b;
	int	d;

	b = 0;
	d = 0;
	letters = 0;
	while (s[letters])
	{
		if (issep(s[letters], c) == 0)
		{
			d = 0;
			while (issep(s[letters + d], c) == 0 && s[letters + d])
				d++;
			tab[b] = malloc(sizeof(char) * (d + 1));
			if (tab[b] == 0)
				return (free_all(tab, b - 1));
			cpy(tab[b++], (char *)s, letters, d);
			letters = d + letters;
		}
		else
			letters++;
	}
	tab[b] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	int		tab_nb;
	char	**tab;

	a = 0;
	tab_nb = 0;
	if (!s)
		return (NULL);
	while (s[a])
	{
		while (s[a] && s[a] == c)
			a++;
		if (s[a] && s[a] != c)
		{
			tab_nb++;
			while (s[a] && s[a] != c)
				a++;
		}
	}
	tab = malloc(sizeof(char *) * (tab_nb + 1));
	if (tab == 0)
		return (NULL);
	return (into_tab(tab, s, c));
}
