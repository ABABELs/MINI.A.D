/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepforexec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:54:17 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/29 16:37:08 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_countcmd(t_list *temp)
{
	t_list	*list;
	t_core	*core;
	int		a;

	list = temp;
	a = 0;
	while (list)
	{
		core = (t_core *)list->content;
		if (core->type == CMD)
			a++;
		else
			break ;
		list = list->next;
	}
	return (a);
}

static char	**ft_cmd_tab(t_list *list, int tab_nb)
{
	t_list	*temp;
	t_core	*core;
	char	**tab;
	int		a;

	tab = malloc(sizeof(char *) * (tab_nb + 1));
	if (!tab)
		return (NULL);
	temp = list;
	a = 0;
	while (temp)
	{
		core = (t_core *)temp->content;
		if (core->type == CMD)
		{
			tab[a] = core->str;
			a++;
		}
		else
			break ;
		temp = temp->next;
	}
	tab[a] = NULL;
	return (tab);
}

void	ft_joincmd(t_mantle *mantle)
{
	t_list	*list;
	t_core	*core;
	int		tab_nb;

	list = mantle->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (core->type == CMD)
		{
			tab_nb = ft_countcmd(list);
			core->tab = ft_cmd_tab(list, tab_nb);
			while (core->type == CMD && list)
			{
				list = list->next;
				if (list)
					core = (t_core *)list->content;
			}
		}
		else
			list = list->next;
	}
}
