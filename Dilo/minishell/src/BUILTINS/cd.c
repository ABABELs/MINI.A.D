/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:25:40 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 14:03:41 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	cd(t_core *core)
// {
// 	char	*path;

//     // Si un chemin est fourni en argument, l'utiliser
// 	if (core->tab[1])
// 		path = core->tab[1];
// 	else
// 	{
//         // Sinon, utiliser la variable d'environnement HOME comme chemin par défaut
// 		path = getenv("HOME");
// 		if (!path)
// 		{
// 			write(STDERR_FILENO, "Error: HOME environment variable not set\\n",
// 				strlen("Error: HOME environment variable not set\\n"));
// 			return ;
// 		}
// 	}
//     // Changer de répertoire
// 	if (chdir(path) != 0)
// 	{
// 		// Gérer les erreurs, par exemple si le répertoire n'est pas trouvé
// 		write(STDERR_FILENO, "Error: Failed to change directory\\n",
// 			strlen("Error: Failed to change directory\\n"));
// 	}
// }

void	cd(t_core *core, t_crust *crust)
{
	char	*path;
	char	*pwd;

	pwd = NULL;
	path = NULL;
	if (chdir(core->tab[1]) != -1)
		return ;
	path = check_tilde(core, crust);
	if (opendir(path) == NULL)
	{
		printf("minishell: cd: %s", core->tab[1]);
		perror(" ");
		core->exit_code = 1;
	}
	else
		chdir(path);
}

char	*check_tilde(t_core *core, t_crust *crust)
{
	char	*path;
	char	*pwd;

	pwd = NULL;
	path = NULL;
	if (core->tab[1] != NULL)
	{
		if (!ft_strncmp("~", core->tab[1], ft_strlen(core->tab[1]))
			|| !ft_strncmp("~/", core->tab[1], ft_strlen(core->tab[1])))
		{
			path = crust->root_path;
			core->tab[1]++;
			if (!ft_strncmp("/", core->tab[1], ft_strlen(core->tab[1])))
				core->tab[1]++;
			if (core->tab[1] != NULL)
				path = ft_strjoin(path, core->tab[1]);
		}
		else
		{
			pwd = getcwd(pwd, 0);
			path = ft_strjoin(pwd, ft_strdup("/"));
			path = ft_strjoin(path, core->tab[1]);
		}
	}
	path = crust->root_path;
	return (path);
}
