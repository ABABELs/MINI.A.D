/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:22:51 by aabel             #+#    #+#             */
/*   Updated: 2023/10/04 10:56:01 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(t_core *core)
{
	char	buffer[CWD_SIZE];

	if (getcwd(buffer, CWD_SIZE) == NULL)
		perror("minishell: pwd: command failed");
	else
	{
		write(core->outfile, buffer, strlen(buffer));
		write(core->outfile, "\n", 1);
	}
}
