/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:15:18 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/09 12:35:44 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

int	ft_print_msg(int a, char *str, int b)
{
	if (a == 1)
	{
		if (str[0] == '|' && str[1] == '\0')
			ft_message("minishell: syntax error near unexpected token `",
				"|", "' \n");
		if (str[0] == '|' && str[1] == '|')
			ft_message("minishell: syntax error near unexpected token `",
				"||", "' \n");
		else
			ft_message("minishell: syntax error near unexpected token `",
				str, "' \n");
	}
	g_mini_sig = 2;
	if (b == 1)
		free(str);
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
