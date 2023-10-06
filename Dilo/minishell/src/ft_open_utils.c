/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:52:32 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/05 21:03:41 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_find_pipe(t_list *list)
{
	t_core	*core;

	while (list && list->next)
	{
		core = (t_core *)list->content;
		if (core->type == PIPE)
			return (1);
		else
			list = list->next;
	}
	return (0);
}

t_core	*ft_find_cmd(t_list *list)
{
	t_core	*core;
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		core = (t_core *)tmp->content;
		if (core->type == CMD && core->tab)
			return (core);
		else if (tmp->next)
			tmp = tmp->next;
		else
			return (NULL);
	}
	return (0);
}

int	ft_redir_error(char *str, t_list *list, int error)
{
	if (ft_find_pipe(list) == 0)
	{
		if (error == -1)
			return (ft_message("minishell: ", str,
					": No such file or directory\n"), exit(1), 1);
		else if (error == -2)
			return (ft_message("minishell: ", str,
					": Permission denied\n"), exit(1), 1);
		else if (error == -3)
			return (ft_message("minishell: ", str,
					": Permission denied\n"), exit(1), 1);
	}
	else
	{
		if (error == -1)
			return (ft_message("minishell: ", str,
					": No such file or directory\n"), 0);
		else if (error == -2)
			return (ft_message("minishell: ", str,
					": Permission denied\n"), 0);
		else if (error == -3)
			return (ft_message("minishell: ", str,
					": Permission denied\n"), 0);
	}
	return (0);
}
