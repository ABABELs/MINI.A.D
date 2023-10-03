/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:32:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/03 14:33:37 by dilovancand      ###   ########.fr       */
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

void	ft_heredoc(t_mantle *mantle)
{
	t_list	*list;

	list = mantle->first;
	if (ft_is_heredoc(mantle) == 1)
		ft_finding_lst(list);
	else
		return ;
}
