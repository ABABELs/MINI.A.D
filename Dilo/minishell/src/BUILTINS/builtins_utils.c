/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:30:33 by arthurabel        #+#    #+#             */
/*   Updated: 2023/10/05 15:41:19 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltins(t_core *core)
{
	if (core->tab == NULL || (*core->tab) == NULL)
		return (0);
	else if (!ft_strncmp("", core->str, ft_strlen(core->str) + 1))
	{
		core->error = 1;
		return (0);
	}
	if (core->tab && *core->tab)
	{
		if (ft_strncmp("echo", (*core->tab), ft_strlen((*core->tab))) == 0)
			return (1);
		else if (ft_strncmp("cd", (*core->tab), ft_strlen((*core->tab))) == 0)
			return (1);
		else if (ft_strncmp("pwd", (*core->tab), ft_strlen((*core->tab))) == 0)
			return (1);
		else if (ft_strncmp("export", (*core->tab), ft_strlen((*core->tab))) == 0)
			return (1);
		else if (ft_strncmp("unset", (*core->tab), ft_strlen((*core->tab))) == 0)
			return (1);
		else if (ft_strncmp("env", (*core->tab), ft_strlen((*core->tab))) == 0)
			return (1);
		else if (ft_strncmp("exit", (*core->tab), ft_strlen((*core->tab))) == 0)
			return (1);
	}
	return (0);
}

void	exec_my_builtins(char *cmd, t_core *core, t_crust *crust)
{
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		ft_echo(core);
	else if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		cd(core, crust);
	else if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		pwd(core);
	else if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		export(crust, core);
	else if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		unset(core, crust);
	else if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		env(crust, core);
	else if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		ft_exit(core);
}

char	**array_join(char **array, char *line)
{
	int		i;
	char	**new_array;
	int		len;

	i = 0;
	if (!array)
		i = 0;
	else
		while (array[i])
			i++;
	len = i;
	new_array = malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i] = ft_strdup(line);
	new_array[++i] = NULL;
	ft_free_array(array);
	return (new_array);
}

void	poop(t_core *core, t_crust *crust)
{
	if (!core->tab[1])
		ft_export_no_args(crust, core);
}
