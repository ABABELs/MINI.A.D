/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepforexec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:54:17 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/05 16:27:32 by dcandan          ###   ########.fr       */
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
		else if (core->type == ARG)
			a++;
		else if (core->type == PIPE)
			break ;
		list = list->next;
	}
	return (a);
}

static char	**ft_cmd_tab2(t_list *temp, int a, char **tab)
{
	t_core	*core;

	while (temp)
	{
		core = (t_core *)temp->content;
		if (core->type == CMD)
		{
			tab[a] = core->str;
			a++;
		}
		else if (core->type == ARG)
		{
			tab[a] = core->str;
			a++;
		}
		else if (core->type == PIPE)
			break ;
		temp = temp->next;
	}
	tab[a] = NULL;
	return (tab);
}

static char	**ft_cmd_tab(t_list *list, int tab_nb)
{
	t_list	*temp;
	char	**tab;
	int		a;

	tab = malloc(sizeof(char *) * (tab_nb + 1));
	if (!tab)
		return (NULL);
	temp = list;
	a = 0;
	return (ft_cmd_tab2(temp, a, tab));
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
