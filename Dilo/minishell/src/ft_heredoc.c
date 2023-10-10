/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/10 15:59:38 by dcandan          ###   ########.fr       */
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
			ft_readdoc(list);
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

void	cmd_fd(t_core *cmd_core, t_core *core)
{
	if (cmd_core)
	{
		cmd_core->error = core->error;
		cmd_core->infile = core->infile;
	}
}

void	ft_heredoc(t_mantle *mantle)
{
	t_list	*list;

	list = mantle->first;
	if (ft_is_heredoc(mantle) == 1)
	{
		ft_finding_lst(list);
	}
	else
		return ;
}
