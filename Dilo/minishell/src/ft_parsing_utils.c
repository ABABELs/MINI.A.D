/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:36:35 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/13 14:13:11 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//parcours la chaine de caractère, vérifie si toutes les quotes sont fermés
int	is_quote_close(char *str)
{
	int	a;
	int	flag_d;
	int	flag_s;

	a = 0;
	flag_d = 0;
	flag_s = 0;
	while (str[a])
	{
		if (str[a] == 39 && flag_s != 2 && flag_d == 0)
			flag_s++;
		if (str[a] == 34 && flag_d != 2 && flag_s == 0)
			flag_d++;
		if (flag_d == 2)
			flag_d = 0;
		if (flag_s == 2)
			flag_s = 0;
		a++;
	}
	if (flag_d != 0 || flag_s != 0)
		return (1);
	return (0);
}

/*
	compare la chaine de caractère avec un char, 
	renvoie un si elle retrouve le char dans la string
*/
int	find_char(char	*tab, char c)
{
	int	a;

	a = 0;
	while (tab[a])
	{
		if (tab[a] == c)
			return (1);
		a++;
	}
	return (0);
}

/*
	print le core
*/
void	print_core(t_mantle *mantle)
{
	t_list	*tmp;
	t_core	*core_tmp;
	int		a;

	tmp = (t_list *)mantle->first;
	a = 0;
	while (tmp)
	{
		core_tmp = (t_core *)tmp->content;
		if (!core_tmp->str)
			return ;
		ft_printf("%s\n", core_tmp->str);
		if (core_tmp->tab)
		{
			while (core_tmp->tab[a])
			{
				ft_printf("cmd tab : %s\n", core_tmp->tab[a]);
				a++;
			}
		}
		ft_printf("%d\n", core_tmp->type);
		tmp = tmp->next;
		a = 0;
	}
}

/*
	check si il y a un $ si oui renvoie 1 sinon 0
*/
int	ft_ispth(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '$')
			return (1);
		a++;
	}
	return (0);
}

//check si il y a une quote renvoie 1 si oui
int	ft_isquote(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == 34 || str[a] == 39)
			return (1);
		a++;
	}
	return (0);
}
