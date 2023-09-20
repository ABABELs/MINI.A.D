/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:30:33 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/20 12:29:20 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltins(t_core *core)
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
	else
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
		exit_shell(core);
}
