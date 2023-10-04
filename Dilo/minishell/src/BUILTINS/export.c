/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:51:38 by arthurabel        #+#    #+#             */
/*   Updated: 2023/10/04 10:55:53 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_syntax(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=' && i > 0)
			return (i);
		else if (!ft_export_char(str[i], i))
		{
			printf("minishell: export: `%s':", str);
			ft_putstr_fd("not a valid identifier\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	ft_export_char(char c, int i)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if ((c >= '0' && c <= '9') && i > 0)
		return (1);
	else if (c == '_')
		return (1);
	return (0);
}

int	ft_check_env(t_crust *crust, char *find_env)
{
	int	i;

	i = -1;
	if (!find_env)
		find_env = ft_strjoin(find_env, ft_strdup("="));
	while (crust->env[++i])
	{
		if (!ft_strncmp(find_env, crust->env[i], ft_strlen(find_env)))
			return (1);
	}
	return (0);
}

void	normed(int *is_syntax, t_core *core, int i)
{
	*is_syntax = ft_check_syntax(core->tab[i]);
	if (*is_syntax < 0)
		core->exit_code = 1;
}

void	export(t_crust *crust, t_core *core)
{
	int	i;
	int	is_syntax;
	int	is_env;

	i = 0;
	is_syntax = 0;
	is_env = 0;
	if (core->outfile != 1)
		return (core->exit_code = 1, (void)0);
	poop(core, crust);
	while (core->tab[++i])
	{
		normed(&is_syntax, core, i);
		if (is_syntax > 0)
		{
			is_env = ft_check_env(crust,
					ft_substr(core->tab[i], 0, is_syntax - 1));
			if (is_env == 0 && !ft_env_exist(crust, core->tab[i]))
			{
				crust->env = array_join(crust->env, core->tab[i]);
				core->exit_code = 0;
			}
		}
	}
}
