/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:23:10 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/04 17:29:55 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*str;

	a = 0;
	str = (unsigned char *) s;
	while (a < n)
	{
		if (str[a] == (unsigned char)c)
			return ((void *)&str[a]);
		a++;
	}
	return (NULL);
}
