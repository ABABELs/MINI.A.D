/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:16:53 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/06 14:34:22 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_open_rout(t_core *cmd_core, t_core *is_fd)
{
	int	fd;

	fd = open(is_fd->str, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		cmd_core->outfile = -1;
		return (-1);
	}
	else
		cmd_core->outfile = fd;
	return (0);
}

static int	ft_open_rin(t_core *cmd_core, t_core *is_fd)
{
	int	fd;

	fd = open(is_fd->str, O_RDONLY);
	if (fd < 0)
	{
		cmd_core->infile = -1;
		return (-1);
	}
	else
		cmd_core->infile = fd;
	return (0);
}

static int	ft_open_append(t_core *cmd_core, t_core *is_fd)
{
	int	fd;

	fd = open(is_fd->str, O_CREAT | O_RDWR, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		cmd_core->outfile = -1;
		return (-1);
	}
	else
		cmd_core->outfile = fd;
	return (0);
}

static int	ft_check_all_fd(t_core *core, t_core *cmd_core, t_core *is_fd)
{
	if (core->type == REDIR_IN && cmd_core && is_fd->type == FD)
	{
		if (ft_open_rin(cmd_core, is_fd) == -1)
			return (-1);
	}
	else if (core->type == REDIR_OUT && cmd_core && is_fd->type == FD)
	{
		if (ft_open_rout(cmd_core, is_fd) == -1)
			return (-2);
	}
	else if (core->type == APPEND && cmd_core && is_fd->type == FD)
	{
		if (ft_open_append(cmd_core, is_fd) == -1)
			return (-3);
	}
	return (0);
}

int	ft_open_fd(t_mantle *mantle)
{
	t_core	*core;
	t_core	*cmd_core;
	t_core	*is_fd;
	t_list	*list;

	list = mantle->first;
	cmd_core = ft_find_cmd(list);
	while (list && list->next)
	{
		is_fd = (t_core *)list->next->content;
		core = (t_core *)list->content;
		if (ft_check_all_fd(core, cmd_core, is_fd) < 0)
			return (ft_redir_error(is_fd->str, list,
					ft_check_all_fd(core, cmd_core, is_fd)));
		cmd_core->exit_code = 0;
		if (core->tab)
			cmd_core = ft_find_cmd(list);
		if (!cmd_core)
			return (-1);
		list = list->next;
	}
	return (0);
}
