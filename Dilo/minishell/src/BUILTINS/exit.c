/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:38:25 by arthurabel        #+#    #+#             */
/*   Updated: 2023/09/13 15:27:05 by arthurabel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_core *core)
{
	int	exit_code;

	exit_code = 0;
    // Si un argument est fourni, le convertir en entier pour le code de sortie
	if (core->tab[1])
		exit_code = atoi(core->tab[1]);
	exit(exit_code);
}