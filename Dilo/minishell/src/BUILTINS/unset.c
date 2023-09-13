/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:43 by aabel             #+#    #+#             */
/*   Updated: 2023/09/13 15:05:05 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void    unset(t_space *space)
// {
//     int		i;
//     int		length;
//     int		res;
// 	int		res_bis;
// 	t_core *current;

// 	current = space->crust;
// 	i = 1;
// 	while (current)
// 	{
// 		space->chatab = ft_split(current->str, ' ');
// 		length = ft_strlen(space->chatab[0]);
// 		if (ft_strncmp(space->chatab[0], "unset", 6) == 0 && length > 1)
// 		{
// 			lwhile (space->chatab[i])
// 			{
// 				res = ft_strncmp(space->chatab[i], "PATH", length);
// 				res_bis = ft_strncmp(space->chatab[i], "HOME", length);
// 				i++;
// 			}
// 		}
// 		current = current->next;
// 	} 
// }

void	unset(t_crust *crust, char *var_to_unset)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
    // Parcourir les variables d'environnement pour trouver la variable à supprimer
	while (data->env[i])
	{
		if (strncmp(data->env[i], var_to_unset, strlen(var_to_unset)) == 0 && data->env[i][strlen(var_to_unset)] == '=')
		{
			found = 1;
			free(data->env[i]);  // Libérer la mémoire de la variable d'environnement trouvée
			j = i;
			// Décaler le reste des variables d'environnement d'une position vers la gauche
			while (data->env[j])
			{
				data->env[j] = data->env[j + 1];
				j++;
			}
			data->env[j] = NULL;  // Mettre la dernière position à NULL après le décalage
			break ;  // Sortir de la boucle car la variable a été supprimée
		}
		i++;
	}
	if (!found)
	{
        // La variable à supprimer n'a pas été trouvée dans l'environnement
        // Gérer ce cas comme vous le souhaitez, par exemple en affichant un message ou en ne faisant rien
    }
}