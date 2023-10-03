/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:51:38 by dcandan           #+#    #+#             */
/*   Updated: 2023/09/29 14:44:38 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	int		a;
// 	int		b;
// 	int		c;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	a = ft_strlen(s1);
// 	b = ft_strlen(s2);
// 	c = 0;
// 	str = (char *)malloc((a + b) + sizeof(char));
// 	if (str == 0)
// 		return (NULL);
// 	while (c < a)
// 	{
// 		str[c] = s1[c];
// 		c++;
// 	}
// 	while (c < (a + b))
// 	{
// 		str[c] = s2[c - a];
// 		c++;
// 	}
// 	str[c] = '\0';
// 	return (str);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	int		sizetotal;
	char	*chainjoin;
	size_t	i;
	size_t	u;

	i = 0;
	u = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	chainjoin = malloc(sizeof(char) * (sizetotal + 1));
	if (!chainjoin)
		return (NULL);
	while (s1 && i < ft_strlen(s1))
	{
		chainjoin[i] = s1[i];
		i++;
	}
	while (s2 && u < ft_strlen(s2))
	{
		chainjoin[i] = s2[u];
		i++;
		u++;
	}
	chainjoin[i] = '\0';
	free(s1);
	return (chainjoin);
}
