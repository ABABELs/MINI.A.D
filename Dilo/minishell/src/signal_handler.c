/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:38:28 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/18 15:32:49 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	redirige le signal sigint pour qu'elle 
	revienne à la ligne avec un nouveau prompt
*/
void	ft_sigint_handler(int si)
{
	(void)si;
	ft_printf("\n");
	rl_on_new_line();
	// rl_replace_line("", 0);
	rl_redisplay();
}

//redirige le signal sigquit pour qu'elle ne fasse rien (à tester)
void	ft_sigquit_handler(int si)
{
	(void)si;
}
