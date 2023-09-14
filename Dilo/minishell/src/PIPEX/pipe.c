/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:16:38 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/14 13:46:28 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_or_not(t_crust *crust)
{
	//verifier si on a bien la bonne qunatiter
	if ((crust->pipe) > 0)
		lanch_pipe(crust);
	else
		return ;
}

void	lanch_pipe(t_crust *crust)
{
	t_core	*content;
	t_list	*list;

	list = crust->lst_cmd->first;
	join_the_pipe(crust);
	while (list)
	{
		content = (t_core *)list->content;
		if (content->type == CMD)
		{
			if (ft_isbuiltins(content) == 1)
				exec_my_builtins(content->tab[0], content, crust);
			content->child = fork();
			if (content->child < 0)
				return (perror("fork failed"));
			else if (content->child == 0)
				run_my_child(content, crust, list);
			if (content->infile > 0)
				close(content->infile);
			if (content->outfile > 2)
				close(content->outfile);
			waitpid(content->child, 0, 0);
		}
			list = list->next;
	}
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
				prev = (t_core *)list->prev->content;
			if (list->next)
				next = (t_core *)list->next->content;
			if (pipe(current->fdp) == -1)
				return (perror("pipe failed"));
			if (prev->error != 1 && prev->outfile == 1 && next->infile == 0)
				prev->outfile = current->fdp[1];
			if (next->error != 1 && next->infile == 0 && prev->outfile == 1)
				next->infile = current->fdp[0];
		}
		list = list->next;
	}
}

void	run_my_child(t_core *cmd, t_crust *crust, t_list *list)
{
	(void)list;
	if (dup2(cmd->infile, STDIN_FILENO) == -1
		|| dup2(cmd->outfile, STDOUT_FILENO) == -1)
		return (perror("dup2 failed"));
	if (cmd->infile > 0)
		close(cmd->infile);
	if (cmd->outfile > 2)
		close(cmd->outfile);
	// get_path(crust, cmd);
	if (execve(crust->path, cmd->tab, crust->env) == -1)//penser a ajouter l env a la struct
		return ;
}
