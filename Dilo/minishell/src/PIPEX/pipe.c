/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:16:38 by arthurabel        #+#    #+#             */
/*   Updated: 2023/10/10 16:00:17 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

static t_list	*ft_lstlast_cmd(t_list *lst)
{
	t_core	*core;
	t_list	*cmd_lst;

	if (!lst)
		return (NULL);
	core = (t_core *)lst->content;
	if (core->type == CMD)
		cmd_lst = lst;
	while (lst->next)
	{
		core = (t_core *)lst->content;
		if (core->type == CMD)
			cmd_lst = lst;
		lst = lst->next;
	}
	return (cmd_lst);
}

void	pipe_or_not(t_crust *crust)
{
	if (ft_count_cmds(crust) > 0)
		lanch_pipe(crust);
	else
		return ;
}

void	wait_all_process(t_crust *crust)
{
	t_list	*list;
	t_core	*core;
	int		exit_code;

	if (!crust->lst_cmd)
		return ;
	list = ft_lstlast_cmd(crust->lst_cmd->first);
	core = (t_core *)list->content;
	while (list && !ft_isbuiltins(core))
	{
		exit_code = 0;
		if (!core->error && core->type == CMD)
			waitpid(core->child, &exit_code, 0);
		if (core->exit_code == 0)
			core->exit_code = WEXITSTATUS(exit_code);
		list = list->prev;
		if (list)
			core = (t_core *)list->content;
	}
}

void	exec_my_pipe(t_core *core, t_crust *crust)
{
	core->child = fork();
	if (core->child > 0)
		ft_signal_in_fork();
	if (core->child < 0)
		return (close_all_fd(crust), perror("Fork failed"), (void)1);
	else if (core->child == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (core->error || core->exit_code)
			exit(1);
		if (dup2(core->infile, STDIN_FILENO) == -1
			|| dup2(core->outfile, STDOUT_FILENO) == -1)
			exit(1);
		close_all_fd(crust);
		if (path_in_cmd(crust, core) == 0)
		{
			if (execve(core->pathed, core->tab, crust->env) == -1)
				exit(127);
		}
		else
			exit(127);
		exit(1);
	}
}

void	lanch_pipe(t_crust *crust)
{
	t_core	*content;
	t_list	*list;

	list = crust->lst_cmd->first;
	remove_pipe(crust);
	while (list)
	{
		content = (t_core *)list->content;
		if (content->type == CMD)
		{
			if (ft_isbuiltins(content) == 1)
			{
				if (!content->error)
					exec_my_builtins(content->tab[0], content, crust);
			}
			else if (ft_strncmp("", content->str, ft_strlen(content->str)))
			{
				exec_my_pipe(content, crust);
			}
			close_fd(content);
		}
		list = list->next;
	}
	wait_all_process(crust);
	ft_signal();
}
