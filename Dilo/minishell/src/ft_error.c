/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:58:42 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/17 21:03:37 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_opos(t_mantle *mantle)
{
	t_list	*list;
	t_core	*core;

	list = mantle->first;
	if (list && list->next)
	{
		core = (t_core *)list->content;
		if (core->type == PIPE)
			return (ft_print_msg(1, core->str));
	}
	else if (list && !list->next)
	{
		core = (t_core *)list->content;
		if (core->type == REDIR_IN || core->type == REDIR_OUT
			|| core->type == APPEND || core->type == HERDOC)
			return (ft_print_msg(1, "newline"));
		else if (core->type == PIPE)
			return (ft_print_msg(1, core->str));
	}
	return (0);
}

static int	ft_after_redirr(t_mantle *mantle)
{
	t_list	*list;
	t_core	*c;

	list = mantle->first;
	while (list && list->next)
	{
		c = (t_core *)list->content;
		if (c->type == REDIR_IN || c->type == REDIR_OUT || c->type == APPEND)
		{
			list = list->next;
			c = (t_core *)list->content;
			if (c->type != FD)
				return (ft_print_msg(1, c->str));
		}
		else
			list = list->next;
	}
	if (!list->next)
	{
		c = (t_core *)list->content;
		if (c->type == 2 || c->type == 3 || c->type == 5 || c->type == 6)
			return (ft_print_msg(1, "newline"));
	}
	return (0);
}

static int	ft_after_pipe(t_mantle *mantle)
{
	t_list	*list;
	t_core	*core;
	int		a;

	list = mantle->first;
	a = 0;
	while (list && list->next)
	{
		core = (t_core *)list->content;
		if (core->type == PIPE)
		{
			if (a == 0)
				return (ft_print_msg(1, core->str));
			list = list->next;
			core = (t_core *)list->content;
		}
		else
			list = list->next;
		a++;
	}
	core = (t_core *)list->content;
	if (core->type == PIPE && !list->next)
		return (ft_print_msg(1, "newline"));
	return (0);
}

int	ft_after_redir(t_mantle *mantle)
{
	if (ft_opos(mantle) == -1)
		return (-1);
	if (ft_after_pipe(mantle) == -1)
		return (-1);
	if (ft_after_redirr(mantle) == -1)
		return (-1);
	return (0);
}
