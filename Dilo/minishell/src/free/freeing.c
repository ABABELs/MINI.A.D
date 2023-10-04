/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:47:54 by aabel             #+#    #+#             */
/*   Updated: 2023/10/04 10:55:22 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	node_to_del(t_mantle *lst_cmd)
{
	t_list		*lst;
	t_core		*core;

	lst = lst_cmd->first;
	while (is_node_to_del(lst))
	{
		core = (t_core *)lst->content;
		if (core->to_delete)
		{
			remove_node(&lst_cmd->first, lst);
			lst = lst_cmd->first;
		}
		else
			lst = lst->next;
	}
}

void	remove_node(t_list **head, t_list *node_to_remove)
{
	if (*head == NULL)
		return ;
	if (*head == node_to_remove)
	{
		*head = node_to_remove->next;
		if (*head)
			(*head)->prev = NULL;
	}
	else
	{
		if (node_to_remove->prev != NULL)
			node_to_remove->prev->next = node_to_remove->next;
		if (node_to_remove->next != NULL)
			node_to_remove->next->prev = node_to_remove->prev;
	}
	if (((t_core *)node_to_remove->content)->str)
		free(((t_core *)node_to_remove->content)->pathed);
	if (((t_core *)node_to_remove->content)->tab != NULL)
		ft_free_array(((t_core *)node_to_remove->content)->tab);
	free(((t_core *)node_to_remove->content)->str);
	free(node_to_remove->content);
	free(node_to_remove);
}

int	is_node_to_del(t_list *lst)
{
	t_core	*core;

	while (lst)
	{
		core = (t_core *)lst->content;
		if (core->to_delete)
			return (1);
		lst = lst->next;
	}
	return (0);
}
