/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:43 by aabel             #+#    #+#             */
/*   Updated: 2023/09/26 14:38:04 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_var(t_crust *crust, char *find_env)
{
	int		i;
	char	**env;

	i = 0;
	env = crust->env;
	while (crust->env[i])
	{
		if (!ft_strncmp(find_env, crust->env[i], strlen(find_env)))
			return (i);
		i++;
	}
	return (i);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**remove_env_var(char **env, int index)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = -1;
	array = malloc(sizeof(char *) * ft_arraylen(env));
	while (env[i])
	{
		if (i != index)
			array[++j] = env[i];
		i++;
	}
	array[j + 1] = NULL;
	return (array);
}

void	unset(t_core *core, t_crust *crust)
{
	int		i;
	int		index;
	char	*env;

	i = 0;
	index = 0;
	env = NULL;
	while (core->tab[++i])
	{
		index = find_env_var(crust, core->tab[i]);
		env = ft_getenv(crust, ft_strdup(core->tab[i]));
		if (env != NULL)
			crust->env = remove_env_var(crust->env, index);
	}
}
