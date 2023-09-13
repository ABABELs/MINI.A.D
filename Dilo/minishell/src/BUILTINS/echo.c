/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:56:03 by aabel             #+#    #+#             */
/*   Updated: 2023/09/13 15:51:42 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_core *core)
{
	int	i;
	int	line;

	i = 1;
	line = 1;
    // Vérifier l'option "-n"
	if (core->tab[i] && strcmp(core->tab[i], "-n") == 0)
	{
		line = 0;
		i++;
	}

    // Imprimer les arguments restants
	while (core->tab[i])
	{
		write(STDOUT_FILENO, core->tab[i], strlen(core->tab[i]));
        // Si ce n'est pas le dernier argument, imprimer un espace
		if (core->tab[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
    // Imprimer une nouvelle ligne à la fin, sauf si l'option "-n" a été spécifiée
	if (line)
		write(STDOUT_FILENO, "\\n", 1);
}

// int	check_n(char **compare)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (compare[++i])
// 	{
// 		j = 0;
// 		if (compare[i][j++] == '-' && compare[i][j] && compare[i][j] == 'n')
// 		{
// 			while (compare[i][j] == 'n')
// 				j++;
// 			if (compare[i][j] && compare[i][j] != 'n')
// 				return (1);
// 		}
// 		else
// 			return (i);
// 	}
// 	return (i);
// }

// void	echo(char **compare, t_space *space)
// {
// 	int	i;
// 	int	k;

// 	k = 0;
// 	i = check_n(compare);
// 	while (compare[i])
// 	{
// 		echo_norme(i, k, compare);
// 		printf(" ");
// 		i++;
// 		k = 0;
// 	}
// 	printf("\n");
// }

// void	exec_echo(t_space *space)
// {
// 	t_core *current;

// 	current = space->crust->content;
// 	while (current)
// 	{
// 		space->chatab = ft_split(current->str, 31);
// 		if (ft_strncmp(space->chatab[0], "echo", 5) == 0)
// 			echo(space->chatab, space);
// 		free_all(space->chatab);
// 		space->chatab = NULL;
// 		current = space->crust->next;
// 	}
// }

// void	echo_norme(int i, int k, char **compare)
// {
	
// }