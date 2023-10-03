/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:51:38 by dcandan           #+#    #+#             */
/*   Updated: 2023/10/03 15:36:19 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
