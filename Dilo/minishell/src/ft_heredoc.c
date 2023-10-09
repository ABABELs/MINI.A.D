/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/09 19:41:12 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quit_heredoc(int sig)
{
	if (sig == SIGINT)
		g_mini_sig = 1000;
	close(STDIN_FILENO);
}

static void	ft_finding_lst(t_list *list)
{
	t_core	*core;

	while (list && list->next)
	{
		core = (t_core *)list->content;
		if (core->type == HERDOC && list->next)
		{
			core = (t_core *)list->next->content;
			ft_readdoc(core, list);
		}
		list = list->next;
	}
}

static int	ft_is_heredoc(t_mantle *mantle)
{
	t_list	*list;
	t_core	*core;

	list = mantle->first;
	while (list && list->next)
	{
		core = (t_core *)list->content;
		if (core->type == HERDOC)
			return (1);
		else
			list = list->next;
	}
	return (0);
}

static void	cmd_fd(t_list *list)
{
	t_core	*core;
	t_core	*cmd_core;
	int		fd;

	fd = 0;
	while (list->next)
	{
		core = (t_core *)list->content;
		if (ft_find_cmd(list))
			cmd_core = ft_find_cmd(list);
		if (core->type == HERDOC)
		{
			core = (t_core *)list->next->content;
			if (cmd_core)
				fd = core->infile;
			if (cmd_core && fd > 0)
				cmd_core->infile = fd;
		}
		list = list->next;
	}
}

void	ft_heredoc(t_mantle *mantle)
{
	t_list	*list;

	list = mantle->first;
	if (ft_is_heredoc(mantle) == 1)
	{
		ft_finding_lst(list);
		cmd_fd(mantle->first);
	}
	else
		return ;
}
