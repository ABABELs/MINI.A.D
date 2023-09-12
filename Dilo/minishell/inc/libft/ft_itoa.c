/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:42:28 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/15 13:42:28 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int nb)
{
	int	a;

	a = 0;
	if (nb == -2147483648)
	{
		nb = 147483648;
		a = 2;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		a++;
	}
	if (nb == 0)
		a++;
	while (nb > 0)
	{
		nb = nb / 10;
		a++;
	}
	return (a);
}

int	putnbrbasee(int n, char *nstr)
{
	if (n == -2147483648)
	{
		nstr[0] = '-';
		nstr[1] = '2';
		n = 147483648;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		a;

	a = count(n);
	str = (char *)malloc(sizeof(char) * (a + 1));
	if (str == 0)
		return (NULL);
	str[a--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
		n = putnbrbasee(n, str);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[a--] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}
