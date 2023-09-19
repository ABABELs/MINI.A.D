/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:04:48 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 17:11:49 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lst_parsing(t_list *lst_parsing)
{
	t_core	*content;

	if (!lst_parsing)
		return ;
	while (lst_parsing)
	{
		content = (t_core *)lst_parsing->content;
		ft_printf("%s", content->str);
		if (content->type == PIPE)
			ft_printf("\tPipe");
		// else if (content->type == HEREDOC)
		// 	ft_printf("\tHeredoc");
		else if (content->type == APPEND)
			ft_printf("\tAppend");
		else if (content->type == CMD)
			ft_printf("\tCmd");
		else if (content->type == FD)
			ft_printf("\tFile");
		// ft_printf("\tDel %d", content->to_delete);
		ft_printf("\tErr %d", content->error);
		if (content->type == CMD)
		{
			ft_printf("\tIn %d", content->infile);
			ft_printf("\tOut %d", content->outfile);
			ft_printf("\tCod %d", content->exit_code);
		}
		if (content->type == PIPE)
		{
			ft_printf("\tIn %d", content->fdp[1]);
			ft_printf("\tOut %d", content->fdp[0]);
		}
		ft_printf("\n");
		lst_parsing = lst_parsing->next;
	}
}