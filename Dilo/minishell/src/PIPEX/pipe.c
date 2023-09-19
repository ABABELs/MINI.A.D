/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:16:38 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/19 14:36:40 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_or_not(t_crust *crust)
{
	if ((crust->pipe) >= 0)
		lanch_pipe(crust);
	else
		return ;
	print_lst_parsing(crust->lst_cmd->first);
}

void	exec_my_pipe(t_core *core, t_crust *crust)
{
	int	exit_code;

	exit_code = 0;
	core->child = fork();
	if (core->child > 0)
		ft_signal_in_fork();
	if (core->child < 0)
	{
		close_fd(core);
		return (perror("fork failed"));
	}
	else if (core->child == 0 && !core->error && !core->exit_code)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		run_my_child(core, crust);
		exit(1);
	}
	if (core->child == 0)
		exit(1);
	waitpid(core->child, &exit_code, 0);
	ft_signal();
	core->exit_code = WEXITSTATUS(exit_code);
}

void	lanch_pipe(t_crust *crust)
{
	t_core	*content;
	t_list	*list;

	list = crust->lst_cmd->first;
	join_the_pipe(crust);
	not_used_pipe(crust);
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
			else
				exec_my_pipe(content, crust);
			close_fd(content);
		}
			list = list->next;
	}
}

void	run_my_child(t_core *cmd, t_crust *crust)
{
	if (dup2(cmd->infile, STDIN_FILENO) == -1
		|| dup2(cmd->outfile, STDOUT_FILENO) == -1)
		exit(1);
	close_fd(cmd);
	path_in_cmd(crust, cmd);
	if (execve(cmd->pathed, cmd->tab, crust->env) == -1)
		return ;
}
