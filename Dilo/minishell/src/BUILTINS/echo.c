/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:56:03 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 12:52:04 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_core *core)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (core->infile > 0)
		core->infile = 0;
	if (core->tab[1] && ft_strncmp(core->tab[1], "-n", 2) == 0)
	{
		flag = 1;
		i++;
	}
	while (core->tab[++i])
	{
		write(core->outfile, core->tab[1], ft_strlen(core->tab[i]));
		if (core->tab[i + 1] != NULL)
			write(core->outfile, " ", 1);
	}
	if (flag == 0)
		write(core->outfile, "\n", 1);
}
