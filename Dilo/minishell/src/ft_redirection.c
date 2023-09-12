/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:09:46 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/12 11:42:37 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// //Work in progress
// static int	ft_redirection(t_mantle *mantle)
// {
// 	t_list	*tmp;
// 	t_core	*core_tmp;

// 	tmp = (t_list *)mantle->first;
// 	while (tmp)
// 	{
// 		core_tmp = (t_core *)tmp->content;
// 		if (core_tmp->str[0] == '>')
// 		{
// 			if (core_tmp->str[1] == '>' && core_tmp->str[2] == '\0')
// 				return (2);
// 			else if (core_tmp->str[1] == '\0')
// 				return (1);
// 		}
// 		else if (core_tmp->str[0] == '<')
// 		{
// 			if (core_tmp->str[1] == '<' && core_tmp->str[2] == '\0')
// 				return (3);
// 			else if (core_tmp->str[1] == '\0')
// 				return (4);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// /*
// 	remplie le tableau de int pipe avec le nombre de pipe qui le précède 
// 	1 si c'est une single pipe, 2 si c'est un double pipe
// 	la valeur est stocker dans crust, dans le int pipe si la récupérer est necessaire,
// */
// static void	ft_pipeo(char *str, t_space *space)
// {
// 	int	a;
// 	int	b;

// 	a = 0;
// 	b = 1;
// 	space->tab[0] = 0;
// 	while (str[a])
// 	{
// 		if (str[a] == '|')
// 		{
// 			if (str[a + 1] == '|' && str[a + 2] != '|')
// 				space->tab[b++] = 2;
// 			else if (str[a + 1] != '|')
// 				space->tab[b++] = 1;
// 			while (str[a] == '|')
// 				a++;
// 		}
// 		else
// 			a++;
// 	}
// }

// //compte le nombre de pipe qu'il y a dans l'input et malloc un tableau de int
// void	ft_pipecount(char *str, t_space *space)
// {
// 	int	a;
// 	int	b;

// 	a = 0;
// 	b = 0;
// 	while (str[a])
// 	{
// 		if (str[a] == '|')
// 		{
// 			if (str[a + 1] == '|' && str[a + 2] != '|')
// 				b++;
// 			else if (str[a + 1] != '|')
// 				b++;
// 			while (str[a] == '|')
// 				a++;
// 		}
// 		else
// 			a++;
// 	}
// 	space->tab = malloc(sizeof(int *) * (b + 2));
// 	if (!space->tab)
// 		return ;
// 	ft_pipeo(str, space);
// }
