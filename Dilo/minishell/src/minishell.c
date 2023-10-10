/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/10 10:45:05 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

static void	malloc_crust_again(char *str, t_crust *crust)
{
	char		*get_env;

	crust->input = (char *)str;
	crust->syntax_error = 0;
	crust->lst_cmd = malloc(sizeof(t_mantle));
	if (!crust->lst_cmd)
		return ;
	crust->lst_cmd->first = NULL;
	get_env = ft_getenv(crust, ft_strdup("PATH"));
	ft_free_array(crust->path);
	crust->path = ft_split(get_env, ':');
	free(crust->root_path);
	crust->root_path = ft_getenv(crust, ft_strdup("HOME"));
	free(get_env);
}

static t_crust	*malloc_crust(char **env)
{
	char		*get_env;
	t_crust		*crust;

	crust = malloc(sizeof(t_crust));
	if (!crust)
		return (NULL);
	crust->env = array_dup(env);
	if (!crust->env)
		return (free(crust->lst_cmd), free(crust), NULL);
	get_env = ft_getenv(crust, ft_strdup("PATH"));
	if (!get_env)
		return (free(crust->lst_cmd), free(crust->env), free(crust), NULL);
	crust->path = ft_split(get_env, ':');
	if (!crust->path)
		return (free(crust->lst_cmd), free(crust->env), free(crust),
			free(get_env), NULL);
	crust->root_path = ft_getenv(crust, ft_strdup("HOME"));
	if (!crust->root_path)
		return (free(crust->lst_cmd), free(crust->env), free(crust),
			free(get_env), free(crust->path), NULL);
	free(get_env);
	return (crust);
}

static void	no_pipe(char *str, t_crust *crust)
{
	char		**tab;

	malloc_crust_again(str, crust);
	tab = ft_minisplit(crust->input);
	if (!tab || !tab[0])
		return (ft_free_crust(crust, 0));
	if (ft_alloc_mantle(tab, crust->lst_cmd, crust) == -1)
		return (ft_free_array(tab), ft_free_crust(crust, 0));
	ft_type_set(crust->lst_cmd);
	if (ft_after_redir(crust->lst_cmd) == -1)
		return (ft_free_array(tab), ft_free_crust(crust, 0));
	(ft_heredoc(crust->lst_cmd), env_var_expension(crust));
	if (remove_quotes(crust->lst_cmd) == -1)
		return (ft_free_array(tab), ft_free_crust(crust, 0));
	if (ft_joincmd(crust->lst_cmd) == -1)
		return (ft_free_array(tab), ft_free_crust(crust, 0));
	if (join_the_pipe(crust) == -1)
		return (ft_free_array(tab), ft_free_crust(crust, 0));
	if (ft_open_fd(crust->lst_cmd) == -1)
		return (ft_free_array(tab), ft_free_crust(crust, 0));
	(pipe_or_not(crust), last_exit_code(crust));
	(ft_free_array(tab), ft_free_crust(crust, 0));
}

//boucle infini, affiche le prompt et gère les arguments envoyer
void	ft_minishell(char **env)
{
	char		*str;
	t_crust		*crust;

	crust = malloc_crust(env);
	if (!crust)
		return (ft_free_crust(crust, 1));
	while (1)
	{
		str = readline("minishell $ ");
		if (str == NULL)
		{
			ft_printf("exit\n");
			break ;
		}
		else
		{	
			if (is_quote_close(str) == 1)
				printf("Quote is not closed\n");
			else
				no_pipe(str, crust);
			add_history(str);
		}
	}
	ft_free_crust(crust, 1);
	free(str);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, ft_sigquit_handler);
	ft_minishell(env);
	return (0);
}
