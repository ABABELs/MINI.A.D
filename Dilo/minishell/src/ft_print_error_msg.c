/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:15:18 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/21 17:43:22 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_msg(int a, char *str)
{
	if (a == 1)
		ft_printf("minishell: syntax error near unexpected token `%s'\n",
			str);
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
