/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:14:56 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/10 10:44:20 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

/*
	récupère la liste chainée contenant les cores les parcours
	retire les quotes qui ne sont pas dans d'autres quotes
	dans la chaine de charactère
*/
int	remove_quotes(t_mantle *mantle)
{
	t_list	*list;
	t_core	*core;
	char	*str;

	list = mantle->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (!core->str)
			return (-1);
		if (ft_isquote(core->str) == 1)
		{
			str = ft_cmdisgood(core->str);
			if (!str)
				return (-1);
			free(core->str);
			core->str = str;
		}
		list = list->next;
	}
	return (0);
}

void	last_exit_code(t_crust *crust)
{
	t_core	*core;
	t_list	*list;

	core = NULL;
	list = crust->lst_cmd->first;
	if (!list)
		g_mini_sig = 0;
	while (list)
	{
		core = (t_core *)list->content;
		if (core->type == CMD)
			g_mini_sig = core->exit_code;
		list = list->next;
	}
}

//un strlen qui renvoie la taille restante de la string
int	ft_path_strlen(char *str, int b)
{
	size_t	a;

	a = 0;
	while (str[a + b])
	{
		a++;
	}
	return (a);
}

/*
	si le caractère envoyer n'est pas une lettre ou un nombre renvoie 1,
	Sert principalement à déterminer la taille de la variable 
	d'environnement en ignorant les caractères
	qui ne peuvent pas être utiliser dans gentenv.
*/
int	check_dollars(char str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')
		|| (str >= '0' && str <= '9'))
		return (0);
	else
		return (1);
}
