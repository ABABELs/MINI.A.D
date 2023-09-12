/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:46:02 by dcandan           #+#    #+#             */
/*   Updated: 2022/12/05 16:30:16 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	thelen(const char *str)
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

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	lenght_dest;
	size_t	lenght_src;
	size_t	a;

	lenght_dest = thelen(dest);
	lenght_src = thelen(src);
	if (size == 0)
		return (lenght_src);
	a = 0;
	if (size < lenght_dest)
		lenght_src = lenght_src + size;
	else
		lenght_src = lenght_src + lenght_dest;
	while (src[a] && ((lenght_dest + 1) < size))
	{
		dest[lenght_dest] = src[a];
		lenght_dest++;
		a++;
	}
	dest[lenght_dest] = '\0';
	return (lenght_src);
}
