/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_crust.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:51:02 by dcandan           #+#    #+#             */
/*   Updated: 2023/10/09 18:15:35 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_core(t_core *core)
{
	if (core->type == REDIR_IN || core->type == REDIR_OUT
		|| core->type == APPEND || core->type == HERDOC || core->type == FD)
		free(core->str);
	if (core->tab)
		ft_free_array(core->tab);
	free(core->pathed);
	free(core);
}

static void	ft_free_mantle(t_mantle *mantle)
{
	t_list	*list;

	list = mantle->first;
	while (list)
	{
		if (!list->next)
			break ;
		list = list->next;
	}
	while (list)
	{
		ft_free_core((t_core *)list->content);
		if (!list->prev)
			break ;
		list = list->prev;
		free(list->next);
	}
	free(list);
}

void	ft_free_crust(t_crust *crust, int a)
{
	if (a == 0)
	{
		if (crust->lst_cmd->first)
			ft_free_mantle(crust->lst_cmd);
		if (crust->lst_cmd)
			free(crust->lst_cmd);
	}
	else
	{
		if (crust->path)
			ft_free_array(crust->path);
		if (crust->env)
			ft_free_array(crust->env);
		if (!crust->root_path)
			;
		else
			free(crust->root_path);
		free(crust);
	}
}
