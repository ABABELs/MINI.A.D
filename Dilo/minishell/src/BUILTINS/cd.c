/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:25:40 by aabel             #+#    #+#             */
/*   Updated: 2023/09/05 16:19:24 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_data *data, char **args)
{
	char	*path;

	(void)data;
    // Si un chemin est fourni en argument, l'utiliser
	if (args[1])
		path = args[1];
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

// void	cd(t_space *space)
// {
// 	if (ft_strncmp (argv[1], "cd", 3) == 0 && argv[2])
// 		change_directory(argv[2], argc, argv);
// }

// void	change_directory(t_space *space)
// {
// 	char	*cwd;
// 	char	*path;

// 	cwd = getcwd(NULL, 0);
// 	path = "";
// 	if (cwd == NULL)
// 	{
// 		perror("error directory");
// 		return ;
// 	}
// 	to_many_line(&dir, &path, &cwd);
// 	if (chdir(path) == 0)
// 		change_env(dir, argc, argv);
// 	else
// 		perror("dir not found");
// 	free(cwd);
// 	free(path);
// }

// void	change_env(char *cwd,t_space *space)
// {
// 	char	*pwd;
// 	char	*oldpwd;

// 	oldpwd = ft_strjoin("OLDPWD=", cwd);
// 	cwd = getcwd(NULL, 0);
// 	pwd = ft_strjoin("PWD=", cwd);
// 	add_var_export()
// }