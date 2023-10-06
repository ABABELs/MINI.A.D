/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:15:18 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/06 15:32:55 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

int	ft_print_msg(int a, char *str)
{
	if (a == 1)
		ft_printf("minishell: syntax error near unexpected token `%s'\n",
			str);
	g_mini_sig = 2;
	return (-1);
}

char	*ft_ministrncpy(char *dest, char *src, int a, int b)
{
	int	c;

	c = 0;
	while (b > c)
	{
		dest[c] = src[c + a];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
