/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minialloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:23:10 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/06 13:26:11 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_alloc_core2(t_core **core)
{
	(*core)->infile = STDIN_FILENO;
	(*core)->outfile = STDOUT_FILENO;
	(*core)->pathed = NULL;
	(*core)->error = 0;
	(*core)->exit_code = 0;
	(*core)->type = NO;
	(*core)->to_delete = 0;
	(*core)->tab = NULL;
	(*core)->child = 0;
}

//malloc et remplie chaque core en définissant son type
static t_core	*ft_alloc_core(char **tab, int a, t_crust *crust)
{
	t_core		*core;
	t_pathport	*path;

	core = malloc(sizeof(t_core));
	if (!core)
		return (NULL);
	core->str = tab[a];
	if (ft_ispth(core->str) == 1)
	{	
		path = malloc(sizeof(t_pathport));
		if (!path)
		{
			free(core);
			return (NULL);
		}
		core->str = ft_print_path(core->str, path, crust);
		free(path);
	}
	ft_alloc_core2(&core);
	if (!core->str)
	{
		free(core);
		return (NULL);
	}
	return (core);
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
