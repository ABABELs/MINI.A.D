/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:36:04 by aabel             #+#    #+#             */
/*   Updated: 2023/09/26 14:14:42 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_crust *crust, char *find_env)
{
	int		i;
	int		len;
	char	**env;

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
			return (ft_substr(env[i], len, ft_strlen(env[i]) - len));
		}
	}
	free(find_env);
	return (NULL);
}
