/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minialloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:23:10 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/07 16:36:34 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_core	*ft_alloc_core2(t_core **core)
{
	if (!(*core)->str)
	{
		free(*core);
		return (NULL);
	}
	(*core)->infile = STDIN_FILENO;
	(*core)->outfile = STDOUT_FILENO;
	(*core)->pathed = NULL;
	(*core)->error = 0;
	(*core)->exit_code = 0;
	(*core)->type = NO;
	(*core)->to_delete = 0;
	(*core)->tab = NULL;
	(*core)->child = 0;
	return (*core);
}

//malloc et remplie chaque core en définissant son type
static t_core	*ft_alloc_core(char **tab, int a, t_crust *crust)
{
	t_core		*core;
	t_pathport	*path;

	core = malloc(sizeof(t_core));
	if (!core)
		return (NULL);
	core->str = ft_strdup(tab[a]);
	if (!core->str)
	{
		free(core);
		return (NULL);
	}
	if (ft_ispth(core->str) == 1)
	{	
		path = malloc(sizeof(t_pathport));
		if (!path)
			return (free(core->str), free(core), NULL);
			path->f = 0;
			path->c = 0;
		free(core->str);
		core->str = ft_print_path(tab[a], path, crust);
		free(path);
	}
	return (ft_alloc_core2(&core));
}

//créer une liste chainée de core dans mantle
int	ft_alloc_mantle(char **tab, t_mantle *mantle, t_crust *crust)
{
	t_core	*tmp;
	t_list	*list_tmp;
	int		a;

	a = -1;
	while (tab[++a])
	{
		tmp = ft_alloc_core(tab, a, crust);
		if (tmp)
		{
			list_tmp = ft_lstnew(tmp);
			ft_lstadd_back(&mantle->first, list_tmp);
		}
		else if (!tmp && !tab[a + 1])
			return (-1);
	}
	return (0);
}
