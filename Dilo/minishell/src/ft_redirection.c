/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:09:46 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/03 14:25:42 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pipe_type(t_mantle *mantle)
{
	t_core	*core;
	t_list	*list;

	list = mantle->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (ft_strcmp(core->str, "|") == 0 && core->type == NO)
			core->type = PIPE;
		list = list->next;
	}
}

static void	ft_redir_type(t_mantle *mantle)
{
	t_core	*core;
	t_list	*list;

	list = mantle->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (ft_strcmp(core->str, ">") == 0 && core->type == NO)
			core->type = REDIR_OUT;
		else if (ft_strcmp(core->str, "<") == 0 && core->type == NO)
			core->type = REDIR_IN;
		else if (ft_strcmp(core->str, ">>") == 0 && core->type == NO)
			core->type = APPEND;
		else if (ft_strcmp(core->str, "<<") == 0 && core->type == NO)
			core->type = HERDOC;
		list = list->next;
	}
}

static void	ft_fd_type(t_mantle *mantle)
{
	t_core	*core;
	t_core	*core2;
	t_list	*list;

	list = mantle->first;
	while (list && list->next)
	{
		core = (t_core *)list->content;
		core2 = (t_core *)list->next->content;
		if ((core->type == REDIR_IN || core->type == REDIR_OUT
				|| core->type == APPEND || core->type == HERDOC)
			&& core2->type == NO)
			core2->type = FD;
		list = list->next;
	}
}

static void	ft_cmd_type(t_mantle *mantle)
{
	t_core	*core;
	t_list	*list;

	list = mantle->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (list->prev == NULL && core->type == NO)
			core->type = CMD;
		if (core->type == NO && ((((t_core *)list->prev->content)->type == CMD)
				|| ((t_core *)list->prev->content)->type == ARG))
			core->type = ARG;
		if (core->type == NO && list->prev != NULL
			&& ((((t_core *)list->prev->content)->type != CMD)
				|| ((t_core *)list->prev->content)->type == PIPE))
			core->type = CMD;
		list = list->next;
	}
}

void	ft_type_set(t_mantle *mantle)
{
	ft_pipe_type(mantle);
	ft_redir_type(mantle);
	ft_fd_type(mantle);
	ft_cmd_type(mantle);
}
