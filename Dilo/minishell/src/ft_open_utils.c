/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:52:32 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/09 17:10:00 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_pipe(t_list *list)
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

static int	ft_find_redir(t_list *list)
{
	t_core	*core;

	while (list && list->next)
	{
		core = (t_core *)list->content;
		if (core->type == FD)
		{
			while (core->type != PIPE)
			{
				list = list->next;
				core = (t_core *)list->content;
				if (core->type == FD)
					return (1);
			}
		}
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

static int	ft_redirmescouilles(char *str, int error)
{
	if (error == -1)
		return (ft_message("minishell: ", str,
				": No such file or directory\n"), 1);
	else if (error == -2)
		return (ft_message("minishell: ", str,
				": Permission denied\n"), 1);
	else if (error == -3)
		return (ft_message("minishell: ", str,
				": Permission denied\n"), 1);
	return (0);
}

int	ft_redir_error(char *str, t_list *list, int error)
{
	if (ft_find_pipe(list) == 0)
	{
		if (error == -1)
			return (ft_message("minishell: ", str,
					": No such file or directory\n"), 1);
		else if (error == -2)
			return (ft_message("minishell: ", str,
					": Permission denied\n"), 1);
		else if (error == -3)
			return (ft_message("minishell: ", str,
					": Permission denied\n"), 1);
	}
	else if (ft_find_pipe(list) == 1 && ft_find_redir(list) == 1)
		return (ft_redirmescouilles(str, error));
	else
	{
		if (error == -1)
			ft_message("minishell: ", str, ": No such file or directory\n");
		else if (error == -2)
			ft_message("minishell: ", str, ": Permission denied\n");
		else if (error == -3)
			ft_message("minishell: ", str, ": Permission denied\n");
	}
	return (0);
}
