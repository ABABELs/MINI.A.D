/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:52:32 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/04 10:53:22 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_core	*ft_find_cmd(t_list *list)
{
	t_core	*core;
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		core = (t_core *)tmp->content;
		if (core->type == CMD && core->tab)
			return (core);
		else if (tmp->next)
			tmp = tmp->next;
		else
			return (NULL);
	}
	return (0);
}
