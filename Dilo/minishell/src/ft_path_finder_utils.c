/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:14:56 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/06 16:05:05 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
