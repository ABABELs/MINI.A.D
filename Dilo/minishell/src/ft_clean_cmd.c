/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:42:08 by dilovancand       #+#    #+#             */
/*   Updated: 2023/08/15 18:37:52 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//un strlen qui ignore les quotes fermés et les multiples espaces 
static int	ft_cmd_strlen(char *str, int a, int b)
{
	char	c;

	while ((str[a] < '!' || str[a] > '~') && str[a])
		a++;
	while (str[a + b])
	{
		if (str[a + b] == 34 || str[a + b] == 39 || str[a + b] == ' ')
		{
			c = str[a + b];
			a++;
			while (str[a + b] != c && str[a + b])
				b++;
			a++;
		}
		else
			b++;
	}
	return (b);
}

//malloc la chaine de caractère
static char	*ft_cmdmalloc(char *str)
{
	char	*tmp;
	int		a;
	int		b;
	int		c;

	b = 0;
	c = 0;
	a = ft_cmd_strlen(str, b, c);
	tmp = malloc(sizeof(char) * (a + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}

//Copie la chaine de charactère
static char	*ft_clean_copy(char *str, int a, char c)
{
	int		b;
	char	*tmp;

	tmp = ft_cmdmalloc(str);
	b = 0;
	while (str[a + b])
	{
		if (str[a + b] == 34 || str[a + b] == 39 || str[a + b] == ' ')
		{
			c = str[a++ + b];
			while (str[a + b] != c && str[a + b])
			{
				tmp[b] = str[a + b];
				b++;
			}
			a++;
		}
		else
		{
			tmp[b] = str[a + b];
			b++;
		}
	}
	tmp[b] = '\0';
	return (tmp);
}

//supprime les quotes et les espaces dans la string pour faciliter le parsing
char	*ft_cmdisgood(char *str)
{
	char	*tmp;
	int		a;
	char	c;

	a = 0;
	c = 0;
	if (ft_isquote(str) == 1)
	{
		while ((str[a] < '!' || str[a] > '~') && str[a])
			a++;
		tmp = ft_clean_copy(str, a, c);
		return (tmp);
	}
	else
		return (str);
}
