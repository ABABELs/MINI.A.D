/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:55:06 by dcandan           #+#    #+#             */
/*   Updated: 2022/12/12 13:55:06 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_print	*ft_ini_tab(t_print *tab)
// {
// 	tab->width = 0;
// 	tab->precision = 0;
// 	tab->zero = 0;
// 	tab->point = 0;
// 	tab->sign = 0;
// 	tab->total_lenght = 0;
// 	tab->is_zero = 0;
// 	tab->dash = 0;
// 	tab->percents = 0;
// 	tab->space = 0;
// 	return (tab);
// }

int	ft_format(va_list tab, const char *str, int pos)
{
	int	ing;

	ing = 0;
	if (str[pos] == 'c')
		ing = ft_putchar(va_arg(tab, int));
	else if (str[pos] == 's')
		ing = ft_putstr(va_arg(tab, char *));
	else if (str[pos] == 'p')
		ing = ft_putvoid(va_arg(tab, unsigned long));
	else if (str[pos] == 'd')
		ing = ft_putnbr(va_arg(tab, int));
	else if (str[pos] == 'i')
		ing = ft_putnbr(va_arg(tab, int));
	else if (str[pos] == 'u')
		ing = ft_putnbrunsigned(va_arg(tab, unsigned int));
	else if (str[pos] == 'x')
		ing = ft_printhexad(va_arg(tab, unsigned int), 'x');
	else if (str[pos] == 'X')
		ing = ft_printhexad(va_arg(tab, unsigned int), 'X');
	else if (str[pos] == '%')
		ing = ft_putperc();
	else
		return (-1);
	return (ing);
}

int	ft_printplus(int a, int c, const char *str, va_list tab)
{
	int	b;

	b = 0;
	while (str[a])
	{
		if (str[a] == '%')
		{
			c = ft_format(tab, str, a + 1);
			if (c == -1)
				return (-1);
			b = b + c;
			a++;
		}
		else
		{
			if (ft_putchar(str[a]) == -1)
				return (-1);
			b++;
		}
		a++;
	}
	return (b);
}

int	ft_printf(const char *str, ...)
{
	int		a;
	va_list	tab;
	int		c;
	int		test;

	a = 0;
	c = 0;
	va_start(tab, str);
	test = ft_printplus(a, c, str, tab);
	va_end(tab);
	return (test);
}
