/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:25:40 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 15:31:05 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_core *core, t_crust *crust)
{
	char	*path;
	char	*pwd;

	pwd = NULL;
	path = NULL;
	if (chdir(core->tab[1]) != -1)
		return ;
	path = check_tilde(core, crust);
	if (opendir(path) == NULL)
	{
		printf("minishell: cd: %s", core->tab[1]);
		perror(" ");
		core->exit_code = 1;
	}
	else
		chdir(path);
}

char	*check_tilde(t_core *core, t_crust *crust)
{
	char	*path;
	char	*pwd;

	pwd = NULL;
	path = NULL;
	if (core->tab[1] != NULL)
	{
		if (!ft_strncmp("~", core->tab[1], ft_strlen(core->tab[1]))
			|| !ft_strncmp("~/", core->tab[1], ft_strlen(core->tab[1])))
		{
			path = crust->root_path;
			core->tab[1]++;
			if (!ft_strncmp("/", core->tab[1], ft_strlen(core->tab[1])))
				core->tab[1]++;
			if (core->tab[1] != NULL)
				path = ft_strjoin(path, core->tab[1]);
		}
		else
		{
			pwd = getcwd(pwd, 0);
			path = ft_strjoin(pwd, ft_strdup("/"));
			path = ft_strjoin(path, core->tab[1]);
		}
	}
	path = crust->root_path;
	return (path);
}
