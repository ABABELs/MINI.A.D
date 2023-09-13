/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:16:38 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/13 10:54:41 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_or_not(t_crust *crust)
{
	//verifier si on a bien la bonne qunatiter
	if (ft_nb_cmd(crust->pipe) > 0)
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
			content->child = fork();
			if (content->type == CMD)
			{
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
}