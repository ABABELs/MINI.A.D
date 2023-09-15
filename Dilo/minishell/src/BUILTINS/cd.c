/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:25:40 by aabel             #+#    #+#             */
/*   Updated: 2023/09/13 15:17:31 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_core *core)
{
	char	*path;

    // Si un chemin est fourni en argument, l'utiliser
	if (core->tab[1])
		path = core->tab[1];
	else
	{
        // Sinon, utiliser la variable d'environnement HOME comme chemin par défaut
		path = getenv("HOME");
		if (!path)
		{
			write(STDERR_FILENO, "Error: HOME environment variable not set\\n",
				strlen("Error: HOME environment variable not set\\n"));
			return ;
		}
	}
    // Changer de répertoire
	if (chdir(path) != 0)
	{
		// Gérer les erreurs, par exemple si le répertoire n'est pas trouvé
		write(STDERR_FILENO, "Error: Failed to change directory\\n",
			strlen("Error: Failed to change directory\\n"));
	}
}
