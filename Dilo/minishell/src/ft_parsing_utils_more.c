/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils_more.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:21:22 by aabel             #+#    #+#             */
/*   Updated: 2023/09/26 16:21:43 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**array_dup(char **array)
{
	int		i;
	char	**new_array;

	i = 0;
	while (array[i])
		i++;
	new_array = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (array[++i])
		new_array[i] = ft_strdup(array[i]);
	new_array[i] = NULL;
	return (new_array);
}
