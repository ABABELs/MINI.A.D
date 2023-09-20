/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:22:51 by aabel             #+#    #+#             */
/*   Updated: 2023/09/19 12:37:46 by aabel            ###   ########.fr       */
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

