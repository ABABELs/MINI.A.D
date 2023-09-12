/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:41:25 by dcandan           #+#    #+#             */
/*   Updated: 2023/01/24 14:19:22 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counthexa(unsigned int n)
{
	int	a;

	a = 0;
	while (n != 0)
	{
		n = n / 16;
		a++;
	}
	return (a);
}

int	ft_printhexa(unsigned int n, char mais)
{
	int	error;

	error = 0;
	if (n >= 16)
	{
		error = ft_printhexa((n / 16), mais);
		if (error == -1)
			return (-1);
		error = ft_printhexa((n % 16), mais);
	}
	else if (error != -1)
	{
		if (n <= 9)
			error = ft_putchar((n + '0'));
		else
		{
			if (mais == 'x')
				error = ft_putchar((n - 10 + 'a'));
			if (mais == 'X')
				error = ft_putchar((n - 10 + 'A' ));
		}
	}
	if (error == -1)
		return (-1);
	return (0);
}

int	ft_printhexad(unsigned int n, char mais)
{
	int	a;
	int	error;

	a = 0;
	error = 0;
	if (n < 0)
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
		error = ft_printhexa(n, mais);
		if (error == -1)
			return (-1);
		a = ft_counthexa(n);
	}
	return (a);
}
