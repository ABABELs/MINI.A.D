/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:36:04 by aabel             #+#    #+#             */
/*   Updated: 2023/10/10 11:42:51 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

char	*ft_getenv(t_crust *crust, char *find_env)
{
	int		i;
	int		len;
	char	**env;
	char	*str;

	i = -1;
	env = crust->env;
	if (find_env)
		find_env = ft_strjoin(find_env, "=");
	len = ft_strlen(find_env);
	while (crust->env[++i])
	{
		if (!strncmp(find_env, crust->env[i], ft_strlen(find_env)))
		{
			free(find_env);
			str = ft_substr(env[i], len, ft_strlen(env[i]) - len);
			if (!str)
				return (NULL);
			else
				return (str);
		}
	}
	free(find_env);
	return (NULL);
}

void	env_var_expension(t_crust *crust)
{
	t_core	*core;
	t_list	*lst_cmd;

	lst_cmd = crust->lst_cmd->first;
	while (lst_cmd)
	{
		core = (t_core *)lst_cmd->content;
		if (is_env_var(core))
			env_to_string(crust, core);
		lst_cmd = lst_cmd->next;
	}
}

int	is_env_var(t_core *core)
{
	int	i;

	i = 0;
	while (core->str[i])
	{
		if (core->str[i] == '$')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*cut_to_getenv(int *i, char *tmp, t_core *core, t_crust *crust)
{
	int		start;
	char	*result;
	char	*env_1;
	char	*env_2;

	env_1 = NULL;
	env_2 = NULL;
	result = NULL;
	start = *i;
	while (core->str[*i] && ft_is_envchar(core->str[*i]) == 1)
		(*i)++;
	env_1 = ft_substr(core->str, start, *i - start);
	env_2 = ft_getenv(crust, env_1);
	result = ft_strjoin(tmp, env_2);
	free(env_2);
	return (result);
}

void	env_to_string(t_crust *crust, t_core *core)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (core->str[i])
	{
		while (core->str[i] && core->str[i] != '$')
			tmp = ft_strjoin_char(tmp, core->str[i++]);
		if (core->str[i] == '$')
			i++;
		if (core->str[i] && ft_is_envchar(core->str[i]) == 1
			&& is_quoted_and_who(core->str, i) != 39)
			tmp = cut_to_getenv(&i, tmp, core, crust);
		else if (ft_is_envchar(core->str[i]) == 2 && core->str[i]
			&& is_quoted_and_who(core->str, i) != 39)
		{
			i++;
			tmp = tmp_itoa(tmp);
		}
		else if (core->str[i - 1] == '$')
			tmp = ft_strjoin_char(tmp, '$');
	}
	free(core->str);
	core->str = tmp;
}
