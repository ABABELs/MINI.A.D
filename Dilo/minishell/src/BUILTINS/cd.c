/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:25:40 by aabel             #+#    #+#             */
/*   Updated: 2023/10/04 14:54:37 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

void	set_pwds(t_crust *crust, char *oldpwd)
{
	int	i;

	i = -1;
	while (crust->env[++i])
	{
		if (!strncmp(crust->env[i], ft_strdup("OLDPWD"), 6))
		{
			free(crust->env[i]);
			crust->env[i] = ft_strjoin(ft_strdup("OLDPWD="), oldpwd);
		}
		if (!strncmp(crust->env[i], ft_strdup("PWD"), 3))
		{
			free(crust->env[i]);
			crust->env[i] = ft_strjoin(ft_strdup("PWD="), getcwd(NULL, 0));
		}
	}
}

int	arg_good(t_core *core, t_crust *crust)
{
	char	*oldpwd;

	oldpwd = ft_getenv(crust, ft_strdup("PWD"));
	if (core->tab && core->tab[1])
	{
		if (chdir(core->tab[1]) != -1)
		{
			set_pwds(crust, oldpwd);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

void	cd(t_core *core, t_crust *crust)
{
	char	*path;
	char	*pwd;

	pwd = NULL;
	path = NULL;
	if (arg_good(core, crust))
		return ;
	if (core->tab[1] != NULL)
		path = check_tilde(core, crust, pwd, path);
	else if (crust->root_path)
		path = crust->root_path;
	else
		return (ft_message("minishell: ", core->str,
				": HOME not set\n"), (void)0);
	if (opendir(path) == NULL)
	{
		printf("minishell: cd: %s", core->tab[1]);
		perror("");
		core->exit_code = 1;
	}
	else
	{
		chdir(path);
		set_pwds(crust, ft_getenv(crust, ft_strdup("PWD")));
	}
}

char	*check_tilde(t_core *core, t_crust *crust, char*pwd, char *path)
{
	if (core->tab[1][0] == '~')
	{
		path = ft_strjoin(path, crust->root_path);
		if (ft_strlen(core->tab[1]) >= 2 && core->tab[1][1] == '/')
		{
			if (core->tab[1][2] != 0)
				path = ft_strjoin(path, &core->tab[1][1]);
		}
		else if (ft_strlen(core->tab[1]) >= 1 && core->tab[1][1] != 0)
			return ((char *)opendir(path));
		else if (ft_strlen(core->tab[1]) >= 2 && core->tab[1][2] != 0)
			return ((char *)opendir(path));
	}
	else
	{
		pwd = getcwd(NULL, 0);
		path = ft_strjoin(ft_strdup(pwd), "/");
		path = ft_strjoin(path, core->tab[1]);
	}
	return (path);
}
