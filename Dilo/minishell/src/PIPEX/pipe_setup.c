/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:05:55 by aabel             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/05 21:24:31 by dilovancand      ###   ########.fr       */
=======
/*   Updated: 2023/10/06 15:37:58 by dcandan          ###   ########.fr       */
>>>>>>> a7ae27d6c67bbcbd356bbdaae9cae4139e2fbc9c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_core	*find_prev(t_list *list)
{
	t_core	*content;

	content = NULL;
	while (list)
	{
		content = ((t_core *)list->content);
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
		current = ((t_core *)list->content);
		if (current->type == PIPE)
		{
			if (list->prev)
				prev = (find_prev(list));
			if (list->next)
				next = ((t_core *)list->next->content);
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

int	ft_slash(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}

int	path_in_cmd(t_crust *crust, t_core *core)
{
	int		i;

	i = -1;
	if (ft_slash(core->str) && opendir(core->str))
		return (ft_message("minishell: ", core->str,
				": is a directory\n"), exit(126), 1);
	if (ft_slash(core->str) && access(core->str, F_OK) != 0)
		return (ft_message("minishell: ", core->str,
				": No such file or directory\n"), exit(127), 1);
	if (ft_slash(core->str) && access(core->str, X_OK) != 0)
		return (ft_message("minishell: ", core->str,
				": Permission denied\n"), exit(126), 1);
	while (crust->path && crust->path[++i])
	{
		core->pathed = ft_strjoin(ft_strdup(crust->path[i]), "/");
		core->pathed = ft_strjoin(core->pathed, core->tab[0]);
		if (access(core->pathed, F_OK | X_OK) == 0)
			return (0);
		else
			free(core->pathed);
	}
	if (access(core->str, F_OK | X_OK) == 0 && !opendir(core->str))
		return (core->pathed = ft_strdup(core->str), 0);
	ft_message("minishell: ", core->tab[0], ": command not found\n");
	return (1);
}
