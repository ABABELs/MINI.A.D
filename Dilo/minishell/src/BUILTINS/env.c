/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:50 by aabel             #+#    #+#             */
/*   Updated: 2023/09/05 15:07:36 by arthurabel       ###   ########.fr       */
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

void	env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		write(STDOUT_FILENO, data->env[i], strlen(data->env[i]));
		write(STDOUT_FILENO, "\\n", 1);  // Ajout d'une nouvelle ligne après chaque variable d'environnement
        i++;
	}
}
