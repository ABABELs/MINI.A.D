/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:50 by aabel             #+#    #+#             */
/*   Updated: 2023/10/03 15:04:13 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_crust *crust, t_core *core)
{
	int	i;

	i = -1;
	if (!crust->env && !(*crust->env))
		return ;
	while (crust->env[++i])
	{
		ft_putstr_fd(crust->env[i], core->outfile);
		write(core->outfile, "\n", 1);
	}
}
