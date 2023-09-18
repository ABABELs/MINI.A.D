/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:50 by aabel             #+#    #+#             */
/*   Updated: 2023/09/18 12:33:48 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// void	print_env(t_space *space)
// {
//     t_core *current;

//     current = space->crust;
//     while (current)
// 	{
// 		space->chatab = ft_split(current->str, ' ');
// 		if (ft_strncmp(space->chatab[0], "env", 4) == 0)
// 			print
// 	}
// }

void	env(t_crust *crust)
{
	int	i;

	i = 0;
	while (crust->env[i])
	{
		write(STDOUT_FILENO, crust->env[i], strlen(crust->env[i]));
		write(STDOUT_FILENO, "\\n", 1);
		i++;
	}
}
