/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:13:29 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/10 15:56:23 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

static void	ft_hsucces(t_core **core, int *fd)
{
	(*core)->infile = fd[0];
	close(fd[1]);
}

static void	ft_hfail(t_core **core, int *fd)
{
	(*core)->error = 1;
	close(fd[1]);
	close(fd[0]);
}

static void	ft_hereline(void)
{
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static int	ft_readingforreal(t_list *list, int fd)
{
	t_core	*nextcore;
	char	*input;

	nextcore = (t_core *)list->next->content;
	signal(SIGINT, quit_heredoc);
	while (1)
	{
		input = readline("> ");
		if (g_mini_sig == 1000)
			exit(1);
		else if (input && !ft_strncmp(input, "\n", ft_strlen(input)))
			ft_hereline();
		else if ((input && !ft_strncmp(input, "", ft_strlen(input)))
			|| input == NULL)
			exit (0);
		else if (input && !ft_strncmp(input, nextcore->str, ft_strlen(input)))
			break ;
		else
			write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
	exit (0);
}

void	ft_readdoc(t_list *list)
{
	pid_t	pid;
	int		fd[2];
	int		exited;
	t_core	*nextcore;

	nextcore = (t_core *)list->content;
	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_readingforreal(list, fd[1]);
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &exited, 0);
	}
	if (!WEXITSTATUS(exited))
		ft_hsucces(&nextcore, fd);
	else
		ft_hfail(&nextcore, fd);
	ft_signal();
}
