/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:53:27 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/03 13:39:34 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	*str;

	a = 0;
	str = (unsigned char *) b;
	while (a < len)
	{
		str[a] = c;
		a++;
	}
	return (b);
}
