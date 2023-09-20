/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:13:33 by dcandan           #+#    #+#             */
/*   Updated: 2023/09/20 12:32:00 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while ((s1[a] == s2[a]) && (s1[a] != '\0') && (a < n))
	{
		a++;
	}
	if (n == a)
		return (0);
	return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
}
