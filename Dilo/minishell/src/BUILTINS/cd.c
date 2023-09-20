/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:25:40 by aabel             #+#    #+#             */
/*   Updated: 2023/09/20 12:01:05 by aabel            ###   ########.fr       */
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
	if (core->tab[1] != NULL)
		path = check_tilde(core, crust, pwd, path);
	else
		path = crust->root_path;
	if (opendir(path) == NULL)
	{
		printf("minishell: cd: %s", core->tab[1]);
		perror(" ");
		core->exit_code = 1;
	}
	else
		chdir(path);
}

char	*check_tilde(t_core *core, t_crust *crust, char*pwd, char *path)
{
	if (!ft_strncmp("~", core->tab[1], 1))
	{
		path = ft_strjoin(path, crust->root_path);
		core->tab[1]++;
		if (!ft_strncmp("/", core->tab[1], 1))
		{
			core->tab[1]++;
			if (core->tab[1][0] != 0)
			{
				path = ft_strjoin(path, ft_strdup("/"));
				path = ft_strjoin(path, core->tab[1]);
			}
		}
		else if (core->tab[1][0] != 0)
			return (NULL);
	}
	else
	{
		pwd = getcwd(pwd, CWD_SIZE);
		path = ft_strjoin(pwd, ft_strdup("/"));
		path = ft_strjoin(path, core->tab[1]);
	}
	return (path);
}
