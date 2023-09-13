/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:51:38 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/13 15:04:51 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_var(t_crust *crust, char *var)
{
	int		len;
	char	**new_env;

	len = 0;
	while (data->env[len])
		len++;
    // Étendre le tableau env d'un slot
	**new_env = realloc(crust->env, sizeof(char *) * (len + 2));
	if (!new_env)
	{
		write(STDERR_FILENO, "Error: Memory allocation failed\\n",
			strlen("Error: Memory allocation failed\\n"));
		return ;
	}
	new_env[len] = strdup(var);
	new_env[len + 1] = NULL;
	crust->env = new_env;
}

void	export(t_crust *crust, char **args)
{
	int	i;

	i = 0;
	if (!args[1])
	{

		while (crust->env[i])
		{
			write(STDOUT_FILENO, crust->env[i], strlen(crust->env[i]));
			write(STDOUT_FILENO, "\\n", 1);
			i++;
		}
	}
	else
	{
		// Ajouter ou modifier la variable d'environnement
		add_env_var(crust, args[1]);
	}
}
