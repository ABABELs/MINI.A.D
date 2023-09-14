/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:43 by aabel             #+#    #+#             */
/*   Updated: 2023/09/14 14:22:27 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_var(char **env, char *var)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], var, strlen(var)) == 0
			&& env[i][strlen(var)] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	**remove_env_var(char **env, int index)
{
	int		env_len;
	int		i;
	int		j;
	char	**new_env;

	env_len = 0;
	i = 0;
	j = 0;
	while (env[env_len])
		env_len++;
	new_env = malloc(sizeof(char *) * env_len);
	while (i < env_len)
	{
		if (i != index)
		{
			new_env[j] = env[i];
		j++;
		}
		else
			free(env[i]);
		i++;
	}
	free(env);
	return (new_env);
}

void	unset(t_core *core, t_crust *crust)
{
	int	arg;
	int	index;

	index = 0;
	arg = 1;
	if (!core->tab[1])
	{
		printf("unset: not enough arguments\n");
		return ;
	}

	while (core->tab[arg])
	{
		index = find_env_var(crust->env, core->tab[arg]);
		if (index != -1)
			crust->env = remove_env_var(crust->env, index);
		arg++;
	}
}


// void	unset(t_core *core, t_crust *crust)
// {
	// int	i;
	// int	j;
	// int	found;

	// i = 0;
	// found = 0;
    // // Parcourir les variables d'environnement pour trouver la variable à supprimer
	// while (crust->env[i])
	// {
	// 	if (strncmp(crust->env[i], , strlen()) == 0 && crust->env[i][strlen()] == '=')
	// 	{
	// 		found = 1;
	// 		free(crust->env[i]);  // Libérer la mémoire de la variable d'environnement trouvée
	// 		j = i;
	// 		// Décaler le reste des variables d'environnement d'une position vers la gauche
	// 		while (crust->env[j])
	// 		{
	// 			crust->env[j] = crust->env[j + 1];
	// 			j++;
	// 		}
	// 		crust->env[j] = NULL;  // Mettre la dernière position à NULL après le décalage
	// 		break ;  // Sortir de la boucle car la variable a été supprimée
	// 	}
	// 	i++;
	// }
	// if (!found)
	// {
    //     // La variable à supprimer n'a pas été trouvée dans l'environnement
    //     // Gérer ce cas comme vous le souhaitez, par exemple en affichant un message ou en ne faisant rien
    // }
// }