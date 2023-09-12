/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:05:20 by dcandan           #+#    #+#             */
/*   Updated: 2023/01/24 14:19:27 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char str)
{
	int	a;

	a = 0;
	a = write(1, &str, 1);
	if (a == -1)
		return (-1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a])
	{
		b = ft_putchar(str[a]);
		if (b == -1)
			return (-1);
		a++;
	}
	return (a);
}

int	ft_putstr(char *str)
{
	int	a;

	a = 0;
	if (str == 0)
	{
		a = ft_printstr("(null)");
		return (a);
	}
	else
		a = ft_printstr(str);
	return (a);
}

int	ft_putnbr(int n)
{
	int		a;
	char	*str;

	a = 0;
	str = ft_itoa(n);
	if (!str)
		return (-1);
	a = ft_putstr(str);
	free (str);
	return (a);
}

int	ft_putperc(void)
{
	int	error;

	error = 0;
	error = write(1, "%", 1);
	if (error == -1)
		return (-1);
	return (1);
}
