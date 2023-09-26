/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:42:18 by aabel             #+#    #+#             */
/*   Updated: 2023/09/20 15:17:22 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_pipe(t_crust *crust)
{
	t_list	*list;

	list = crust->lst_cmd->first;
	while (list)
	{
		if (((t_core *)list->content)->type == PIPE)
			(((t_core *)list->content)->to_delete = 1);
		list = list->next;
	}
	node_to_del(crust->lst_cmd);
}

void	close_fd(t_core *core)
{
	if (core->infile > 0)
		close(core->infile);
	if (core->outfile > 2)
		close(core->outfile);
}

void	close_all_fd(t_crust *crust)
{
	t_list	*list;
	t_core	*core;

	list = crust->lst_cmd->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (core->infile > 0)
			close(core->infile);
		if (core->outfile > 2)
			close(core->outfile);
		list = list->next;
	}
}
