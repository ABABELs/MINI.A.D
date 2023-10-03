/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minialloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:23:10 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/03 13:45:33 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			return (NULL);
		core->str = ft_print_path(core->str, path, crust);
	}
	core->infile = STDIN_FILENO;
	core->outfile = STDOUT_FILENO;
	core->pathed = NULL;
	core->error = 0;
	core->exit_code = 0;
	core->type = NO;
	core->to_delete = 0;
	if (!core->str)
		return (core);
	return (core);
}

//créer une liste chainée de core dans mantle
void	ft_alloc_mantle(char **tab, t_mantle *mantle, t_crust *crust)
{
	t_core	*tmp;
	t_list	*list_tmp;
	int		a;

	a = -1;
	while (tab[++a])
	{
		tmp = ft_alloc_core(tab, a, crust);
		list_tmp = ft_lstnew(tmp);
		ft_lstadd_back(&mantle->first, list_tmp);
	}
}
