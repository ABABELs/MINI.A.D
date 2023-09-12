/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:32:56 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/24 13:32:56 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero2(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}

size_t	ft_strlen2(const char *str)
{
	size_t	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		a++;
	}
	return (a);
}

void	*ft_calloc2(size_t count, size_t size)
{
	void	*jsp;

	jsp = (void *)malloc(count * size);
	if (jsp == 0)
		return (0);
	ft_bzero2(jsp, count * size);
	return (jsp);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;
	int		c;

	if (!s1 && !s2)
		return (NULL);
	a = ft_strlen2(s1);
	b = ft_strlen2(s2);
	c = -1;
	str = (char *)malloc((a + b) + sizeof(char));
	if (!str)
	{
		free(s1);
		return (str = NULL);
	}
	while (++c < a)
		str[c] = s1[c];
	c--;
	while (++c < (a + b))
		str[c] = s2[c - a];
	str[c] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr2(const char *s, int c)
{
	int	a;

	a = 0;
	while (s && s[a])
	{
		if (s[a] == (char)c)
			return ((char *)&s[a]);
		a++;
	}
	if (s && s[a] == (char)c)
	{
		return ((char *)&s[a]);
	}
	return (NULL);
}
