/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:37:58 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/04 18:02:24 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		a;
	int		len;
	char	*c;

	a = 0;
	len = 0;
	while (str[len])
		len++;
	c = (char *)malloc(sizeof(*c) * (len + 1));
	if (c == 0)
		return (0);
	while (str[a])
	{
		c[a] = str[a];
		a++;
	}
	c[a] = '\0';
	return (c);
}
