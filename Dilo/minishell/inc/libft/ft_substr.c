/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:47:43 by dcandan           #+#    #+#             */
/*   Updated: 2023/10/04 16:38:12 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_min(int a)
{
	char	*c;

	c = (char *)malloc(sizeof(char));
	if (!c)
		return (NULL);
	c[a] = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*c;

	a = 0;
	if (!s)
		return (NULL);
	if ((ft_strlen(s) <= start || len == 0))
		return (malloc_min(a));
	if (len > (ft_strlen(s) - start))
		c = malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else
		c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	while (len > a && a < (ft_strlen(s) - start))
	{
		c[a] = s[a + start];
		a++;
	}
	c[a] = '\0';
	return (c);
}
