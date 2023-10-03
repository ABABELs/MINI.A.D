/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:38:28 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/03 14:08:14 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

/*
	redirige le signal sigint pour qu'elle 
	revienne à la ligne avec un nouveau prompt
*/
void	ft_sigint_handler(int si)
{
	(void)si;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

//redirige le signal sigquit pour qu'elle ne fasse rien (à tester)
void	ft_sigquit_handler(int si)
{
	(void)si;
}

//added
void	ft_signal_in_fork(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

//added
void	ft_signal(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

//added
void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_mini_sig = 130;
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
