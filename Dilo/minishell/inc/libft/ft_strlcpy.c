/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:30:00 by dcandan           #+#    #+#             */
/*   Updated: 2022/12/05 16:18:20 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (src[b])
		b++;
	if (dstsize < 1)
		return (b);
	while (src[a] && a < (dstsize - 1))
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	while (src[a])
		a++;
	return (a);
}
