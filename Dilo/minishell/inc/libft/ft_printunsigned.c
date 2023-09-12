/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:15:54 by dcandan           #+#    #+#             */
/*   Updated: 2022/12/19 15:15:54 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countunsigned(unsigned int n)
{
	int	a;

	a = 0;
	if (n == 0)
		a++;
	while (n > 0)
	{
		n = n / 10;
		a++;
	}
	return (a);
}

char	*ft_unsigneditoa(unsigned int n)
{
	char	*str;
	int		a;

	a = ft_countunsigned(n);
	str = malloc(sizeof(char) * (a + 1));
	if (!str)
		return (NULL);
	str[a] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[a - 1] = 48 + (n % 10);
		n = n / 10;
		a--;
	}
	return (str);
}

int	ft_putnbrunsigned(unsigned int n)
{
	int		a;
	char	*str;

	a = 0;
	str = ft_unsigneditoa(n);
	if (!str)
		return (-1);
	a = ft_putstr(str);
	free (str);
	return (a);
}
