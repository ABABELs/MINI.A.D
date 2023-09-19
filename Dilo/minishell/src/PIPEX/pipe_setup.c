/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:05:55 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 13:58:16 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(t_core *core)
{
	if (core->infile > 0)
		close(core->infile);
	if (core->outfile > 2)
		close(core->outfile);
}

t_core	*find_prev(t_list *list)
{
	t_core	*content;

	content = NULL;
	while (list)
	{
		content = (t_core *)list->content;
		if (content->type == CMD)
			break ;
		list = list->prev;
	}
	return (content);
}

void	join_the_pipe(t_crust *crust)
{
	t_list	*list;
	t_core	*prev;
	t_core	*next;
	t_core	*current;

	list = crust->lst_cmd->first;
	while (list)
	{
		current = (t_core *)list->content;
		if (current->type == PIPE)
		{
			if (list->prev)
				prev = (find_prev(list));
			if (list->next)
				next = (t_core *)list->next->content;
			if (pipe(((t_core *)list->content)->fdp) == -1)
				return (perror("pipe failed"));
			prev->outfile = current->fdp[1];
			current->infile = current->fdp[1];
			next->infile = current->fdp[0];
			current->outfile = current->fdp[0];
		}
		list = list->next;
	}
}

void	not_used_pipe(t_crust *crust)
{
	t_list	*list;
	t_core	*current;
	t_core	*prev;
	t_core	*next;

	list = crust->lst_cmd->first;
	while (list)
	{
		if (!list->next && !list->prev)
			break ;
		current = (t_core *)list->content;
		if (current->type == PIPE)
		{
			prev = (t_core *)list->prev->content;
			next = (t_core *)list->next->content;
			if ((prev->outfile == current->infile
					&& current->outfile == next->infile))
				prev->outfile = -1;
			if ((prev->outfile != current->infile
					&& current->outfile != next->infile))
				next->infile = -1;
		}
		list = list->next;
	}
}

void	path_in_cmd(t_crust *crust, t_core *core)
{
	int		i;

	i = -1;
	if (access(core->str, X_OK) == 0)
	{
		core->pathed = ft_strdup(core->str);
		return ;
	}
	while (crust->path[++i])
	{
		core->pathed = ft_strjoin(crust->path[i], "/");
		core->pathed = ft_strjoin(core->pathed, core->tab[0]);
		if (access(core->pathed, X_OK) == 0)
			return ;
	}
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, core->tab[0], ft_strlen(core->tab[0]));
}
