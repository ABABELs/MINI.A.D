/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:47:43 by dcandan           #+#    #+#             */
/*   Updated: 2022/12/27 16:53:10 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_min(int a)
{
	char	*c;

	c = (char *)malloc(sizeof(char));
	if (c == 0)
		return (0);
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
		c = (char *)malloc(sizeof(*c) * (ft_strlen(s) - start) + 1);
	else
		c = (char *)malloc(sizeof(*c) * (len + 1));
	if (c == 0)
		return (0);
	while (len > a && a < (ft_strlen(s) - start))
	{
		c[a] = s[a + start];
		a++;
	}
	c[a] = '\0';
	return (c);
}
