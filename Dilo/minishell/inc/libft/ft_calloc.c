/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:13:50 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/03 17:35:59 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*jsp;

	jsp = (void *)malloc(count * size);
	if (jsp == 0)
		return (0);
	ft_bzero(jsp, count * size);
	return (jsp);
}
