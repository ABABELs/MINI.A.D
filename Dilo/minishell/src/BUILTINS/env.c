/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:50 by aabel             #+#    #+#             */
/*   Updated: 2023/10/09 15:53:02 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

void	env(t_crust *crust, t_core *core)
{
	int	i;

	i = 0;
	if (!crust->env && !(*crust->env))
		return ;
	while (crust->env[i])
	{
		ft_putstr_fd(crust->env[i], core->outfile);
		i++;
	}
}

void	ft_export_no_args(t_crust *crust, t_core *core)
{
	char	**new;

	new = NULL;
	if (!crust->env && !(*crust->env))
		return ;
	new = ft_sort_env(crust->env, new);
	ft_env_no_args(new, core);
}

char	**ft_sort_env(char **env, char **new)
{
	int		i;
	int		u;
	char	*tmp;

	i = -1;
	u = -1;
	tmp = NULL;
	new = array_dup(env);
	while (new[++i])
	{
		while (new[++u])
		{
			if (new[u + 1] && new[u]
				&& ft_strncmp(new[u], new[u + 1], ft_strlen(new[u]) + 1) > 0)
			{
				tmp = new[u];
				new[u] = new[u + 1];
				new[u + 1] = tmp;
			}
		}
		u = -1;
	}
	return (new);
}

void	ft_env_no_args(char **env, t_core *core)
{
	int	i;
	int	u;
	int	flag;

	i = -1;
	u = 0;
	flag = 0;
	while (env[++i])
	{
		write(core->outfile, "declare -x ", 11);
		while (env[i][u])
		{
			write(core->outfile, &env[i][u], 1);
			if (env[i][u] == '=' && flag == 0)
			{
				write(core->outfile, "\"", 1);
				flag = 1;
			}
			u++;
		}
		flag = 0;
		write(core->outfile, "\"\n", 2);
		u = 0;
	}
	ft_free_array(env);
}

int	ft_env_exist(t_crust *crust, char *env)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (crust->env[++i])
	{
		while (crust->env[i][len] != '=')
			len++;
		if (!ft_strncmp(env, crust->env[i], len + 1))
		{
			crust->env[i] = ft_strdup(env);
			return (1);
		}
		len = 0;
	}
	return (0);
}
