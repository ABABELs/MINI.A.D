/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:19:54 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/04 17:18:37 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (a < len && haystack[a] != '\0')
	{	
		b = 0;
		while (haystack[a + b] == needle[b] && a + b < len)
		{
			if (needle[b + 1] == '\0')
				return ((char *)haystack + a);
			b++;
		}
		a++;
	}
	return (0);
}
