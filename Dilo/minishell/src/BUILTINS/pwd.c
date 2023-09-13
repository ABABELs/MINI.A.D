/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:22:51 by aabel             #+#    #+#             */
/*   Updated: 2023/09/13 15:00:21 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	pwd(t_space *space)
// {
// 	char	*cwd;
// 	t_space	*current;

// 	current = space->crust;
// 	while (current)
// 	{
// 		space->chatab = ft_split(current->input, ' ');
// 		if (ft_strncmp(space->tab[0], "pwd", 4) == 0)
// 		{
// 			cwd = getcwd(NULL, 0);
// 			if (cwd == NULL)
// 			{
// 				perror("error directory");
// 				return ;
// 			}
// 			printf("%s\n", cwd);
// 			free(cwd);
// 		}
// 		free(space->chatab);
// 		space->chatab = NULL;
// 		current = current->crust->next;
// 	}
// }

void	pwd(t_crust *crust)
{
	char	buffer[4096];
	// On suppose une taille maximale de chemin de 4096

	if (getcwd(buffer, sizeof(buffer)) != NULL)
	{
		write(STDOUT_FILENO, buffer, strlen(buffer));
		write(STDOUT_FILENO, "\\n", 1); // Ajout d'une nouvelle ligne après l'affichage du chemin
	}
	else
	{
        // Gérer l'erreur, par exemple en affichant un message d'erreur
		write(STDERR_FILENO, "Error: Unable to get current working directory\\n",
			strlen("Error: Unable to get current working directory\\n"));
	}
}

