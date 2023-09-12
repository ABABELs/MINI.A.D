/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:03:34 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/04 17:34:56 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			a;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	a = 0;
	if (n == 0)
		return (0);
	while ((str1[a] == str2[a]) && (a < (n - 1)))
	{
		a++;
	}
	if (n == a)
		return (0);
	return ((int)str1[a] - str2[a]);
}
