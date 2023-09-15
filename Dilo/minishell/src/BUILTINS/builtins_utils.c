/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:30:33 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/14 13:50:23 by arthurabel       ###   ########.fr       */
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
	if (ft_strncmp("echo", cmd, ft_strlen(cmd)) == 0)
		ft_echo(core);
	else if (ft_strncmp("cd", cmd, ft_strlen(cmd)) == 0)
		cd(core);
	else if (ft_strncmp("pwd", cmd, ft_strlen(cmd)) == 0)
		pwd(crust);
	else if (ft_strncmp("export", cmd, ft_strlen(cmd)) == 0)
		export(core, crust);
	else if (ft_strncmp("unset", cmd, ft_strlen(cmd)) == 0)
		unset(core, crust);
	else if (ft_strncmp("env", cmd, ft_strlen(cmd)) == 0)
		env(crust);
	else if (ft_strncmp("exit", cmd, ft_strlen(cmd)) == 0)
		exit_shell(core);
}
