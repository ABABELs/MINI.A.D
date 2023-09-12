/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:55:31 by dcandan           #+#    #+#             */
/*   Updated: 2022/12/05 16:18:06 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	while (a < n)
	{
		((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dst);
}
