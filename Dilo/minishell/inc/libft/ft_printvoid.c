/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:18:53 by dcandan           #+#    #+#             */
/*   Updated: 2023/01/24 14:19:35 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countvoid(unsigned long long n)
{
	int	a;

	a = 0;
	while (n != 0)
	{
		a++;
		n = n / 16;
	}
	return (a);
}

int	ft_printvoid(unsigned long long n)
{
	int	error;

	error = 0;
	if (n >= 16)
	{
		ft_printvoid(n / 16);
		ft_printvoid(n % 16);
	}
	else
	{
		if (n <= 9)
			error = ft_putchar((n + '0'));
		else
			error = ft_putchar((n - 10 + 'a'));
	}
	if (error == -1)
		return (-1);
	return (0);
}

int	ft_putvoid(unsigned long long n)
{
	int	a;
	int	error;

	a = 0;
	a = a + write(1, "0x", 2);
	if (a == -1)
		return (-1);
	if (n == 0)
	{
		error = write(1, "0", 1);
		if (error == -1)
			return (-1);
		a++;
	}
	else
	{
		error = ft_printvoid(n);
		if (error == -1)
			return (-1);
		a = a + ft_countvoid(n);
	}
	return (a);
}
