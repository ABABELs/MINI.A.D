/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:51:38 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/30 14:24:15 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	c = 0;
	str = (char *)malloc((a + b) + sizeof(char));
	if (str == 0)
		return (NULL);
	while (c < a)
	{
		str[c] = s1[c];
		c++;
	}
	while (c < (a + b))
	{
		str[c] = s2[c - a];
		c++;
	}
	str[c] = '\0';
	return (str);
}
