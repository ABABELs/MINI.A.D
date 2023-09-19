/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:43 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 17:08:53 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_var(char **env, char *var)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], var, strlen(var)) == 0
			&& env[i][strlen(var)] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	**remove_env_var(char **env, int index)
{
	int		env_len;
	int		i;
	int		j;
	char	**new_env;

	env_len = 0;
	i = 0;
	j = 0;
	while (env[env_len])
		env_len++;
	new_env = malloc(sizeof(char *) * env_len);
	while (i < env_len)
	{
		if (i != index)
		{
			new_env[j] = env[i];
		j++;
		}
		else
			free(env[i]);
		i++;
	}
	free(env);
	return (new_env);
}

void	unset(t_core *core, t_crust *crust)
{
	int	arg;
	int	index;

	index = 0;
	arg = 1;
	if (!core->tab[1])
	{
		printf("unset: not enough arguments\n");
		return ;
	}

	while (core->tab[arg])
	{
		index = find_env_var(crust->env, core->tab[arg]);
		if (index != -1)
			crust->env = remove_env_var(crust->env, index);
		arg++;
	}
}
