/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:51:38 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/19 18:02:37 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (core->tab[++i])
	{
		is_syntax = check_syntax(core->tab[i]);
		if (is_syntax < 0)
			core->exite_code = 1;
		if (is_syntax > 0)
		{
			is_env = check_env(crust,
					ft_substr(core->tab[i], 0, is_syntax - 1));
			if (is_env == 0)
			{
				crust->env = array_join(crust->env, core->tab[i]);
				core->exit_code = 0;
			}
		}
	}
}

int	check_syntax(char *str)
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

int	check_env(t_crust *crust, char *find_env)
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

// void	add_env_var(t_crust *crust, char *var)
// {
// 	int		len;
// 	char	**new_env;

// 	len = 0;
// 	new_env = NULL;
// 	while (crust->env[len])
// 		len++;
// 	new_env = realloc(crust->env, sizeof(char *) * (len + 2));
// 	if (!new_env)
// 	{
// 		write(STDERR_FILENO, "Error: Memory allocation failed\\n",
// 			strlen("Error: Memory allocation failed\\n"));
// 		return ;
// 	}
// 	new_env[len] = strdup(var);
// 	new_env[len + 1] = NULL;
// 	crust->env = new_env;
// }

// void	export(t_crust *crust, t_core *core)
// {
// 	int	i;

// 	i = 0;
// 	if (!core->tab[1])
// 	{
// 		while (crust->env[i])
// 		{
// 			write(STDOUT_FILENO, crust->env[i], strlen(crust->env[i]));
// 			write(STDOUT_FILENO, "\\n", 1);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		add_env_var(crust, crust->env[1]);
// 	}
// }