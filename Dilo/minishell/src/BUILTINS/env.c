/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:50 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 17:37:31 by aabel            ###   ########.fr       */
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
	}
}
