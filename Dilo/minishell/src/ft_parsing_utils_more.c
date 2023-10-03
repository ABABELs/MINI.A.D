/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils_more.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:21:22 by aabel             #+#    #+#             */
/*   Updated: 2023/10/03 14:06:24 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**array_dup(char **array)
{
	int		i;
	char	**new_array;

	i = 0;
	while (array[i])
		i++;
	new_array = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (array[++i])
		new_array[i] = ft_strdup(array[i]);
	new_array[i] = NULL;
	return (new_array);
}

void	pipe_syntax_checker(t_crust *crust, t_list *list)
{
	t_core	*core;

	while (list)
	{
		core = (t_core *)list->content;
		if ((core->type == PIPE && list->prev == NULL)
			|| (core->type == PIPE && list->next
				&& ((t_core *)list->next->content)->type == PIPE))
		{
			ft_message("minishell: syntax error near unexpected token `"
				, core->str, "'\n");
			crust->syntax_error = 1;
			g_mini_sig = 2;
			return ;
		}
		else if (core->type == PIPE && list->next == NULL)
		{
			ft_message("minishell: syntax error near unexpected token `"
				, core->str, "'\n");
			crust->syntax_error = 1;
			g_mini_sig = 2;
			return ;
		}
		list = list->next;
	}
}
