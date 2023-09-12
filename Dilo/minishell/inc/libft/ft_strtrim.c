/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:32:12 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/08 14:32:12 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *str, char c)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == c)
			return (1);
		a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		a;
	int		b;
	int		c;

	if (!s1 || !set)
		return (NULL);
	a = 0;
	b = ft_strlen(s1);
	c = 0;
	while (s1[a] && in_set(set, s1[a]) == 1)
		a++;
	if (a != b)
	{
		while (s1[b - 1] && in_set(set, s1[b - 1]) == 1)
			b--;
	}
	str = malloc(sizeof(char) * (b - a) + 1);
	if (str == 0)
		return (NULL);
	while (a < b)
		str[c++] = s1[a++];
	str[c] = '\0';
	return (str);
}
