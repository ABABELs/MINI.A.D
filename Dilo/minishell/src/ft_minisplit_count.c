/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisplit_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:17:39 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/15 13:31:30 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ez_count(char *s, char flag, int a)
{
	a++;
	while (s[a] != flag)
		a++;
	a++;
	return (a);
}

static int	ft_verif(char *s, int a)
{
	if (s[a] != ' ' && s[a] != '\t' && s[a] != '>'
		&& s[a] != '<' && s[a] && s[a] != '|'
		&& (s[a + 1] == '>' || s[a + 1] == '<'
			|| s[a + 1] == '|' || s[a + 1] == '\0'))
		return (1);
	else
		return (0);
}

static int	ft_verif2(char *s, int a, char c)
{
	if (s[a] == c && ((s[a + 1] != ' ' && s[a + 1] != c)
			|| (s[a + 1] != '\t' && s[a + 1] != c)))
		return (1);
	else if (s[a] == c && s[a + 1] == '\0'
		&& s[a - 1] != ' ' && s[a - 1] != '\t')
		return (2);
	return (0);
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
				else if (ft_verif(s, a) == 1)
					tab_nb++;
				if (s[a] == 34 || s[a] == 39)
				{
					a = ez_count (s, s[a], a);
					tab_nb++;
				}
				else
					a++;
			}
		}
	}
	return (tab_nb);
}

/*
	compte le nombre de case à allouer dans le tableau
	ignore tout ce qui se trouve entre single ou double quote
*/
int	ft_redir_count(char *s, char c, int a, int tab_nb)
{
	while (s[a])
	{
		while (s[a] == c)
		{
			if (ft_verif2(s, a, c) == 1)
				tab_nb++;
			else if (ft_verif2(s, a, c) == 2)
				tab_nb++;
			a++;
		}
		if (s[a] && s[a] != c)
		{
			while (s[a] && s[a] != c)
			{
				if (s[a] == 34 || s[a] == 39)
					a = ez_count (s, s[a], a);
				else
					a++;
			}
		}
	}
	return (tab_nb);
}
