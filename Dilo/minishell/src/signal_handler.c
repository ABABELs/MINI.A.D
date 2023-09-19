/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:38:28 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/19 15:30:22 by aabel            ###   ########.fr       */
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
	// rl_replace_line("", 0);
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
	struct sigaction	s_sigaction;

	s_sigaction.sa_flags = 0;
	s_sigaction.sa_sigaction = sig_handler;
	sigaction(SIGINT, &s_sigaction, 0);
	signal(SIGQUIT, SIG_IGN);
}

//added
void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGINT)
	{
		g_mini_sig = 130;
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
