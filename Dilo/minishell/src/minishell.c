/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/08 14:29:34 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_mini_sig;

/*
	récupère la liste chainée contenant les cores les parcours
	retire les quotes qui ne sont pas dans d'autres quotes
	dans la chaine de charactère
*/
static int	remove_quotes(t_mantle *mantle)
{
	t_list	*list;
	t_core	*core;
	char	*str;

	list = mantle->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (!core->str)
			return (-1);
		if (ft_isquote(core->str) == 1)
		{
			str = ft_cmdisgood(core->str);
			if (!str)
				return (-1);
			free(core->str);
			core->str = str;
		}
		list = list->next;
	}
	return (0);
}

static t_crust	*malloc_crust(const char *str, char **env)
{
	char		*get_env;
	t_crust		*crust;

	crust = malloc(sizeof(t_crust));
	crust->lst_cmd = malloc(sizeof(t_mantle));
	crust->lst_cmd->first = NULL;
	if (!crust || !crust->lst_cmd)
		return (NULL);
	crust->input = (char *)str;
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

static void	no_pipe(const char *str, char **env)
{
	t_crust		*crust;
	char		**tab;

	crust = malloc_crust(str, env);
	if (!crust)
		return ;
	crust->syntax_error = 0;
	tab = ft_minisplit(crust->input);
	if (!tab || !tab[0])
		return (ft_free_crust(crust));
	if (ft_alloc_mantle(tab, crust->lst_cmd, crust) == -1)
		return (ft_free_crust(crust));
	ft_type_set(crust->lst_cmd);
	if (ft_after_redir(crust->lst_cmd) == -1)
		return (ft_free_crust(crust));
	(ft_heredoc(crust->lst_cmd), env_var_expension(crust));
	if (remove_quotes(crust->lst_cmd) == -1)
		return (ft_free_crust(crust));
	if (ft_joincmd(crust->lst_cmd) == -1)
		return (ft_free_crust(crust));
	if (join_the_pipe(crust) == -1)
		return (ft_free_crust(crust));
	(ft_open_fd(crust->lst_cmd), pipe_or_not(crust), last_exit_code(crust));
	(ft_free_array(tab), ft_free_crust(crust));
}

//boucle infini, affiche le prompt et gère les arguments envoyer
void	ft_minishell(char **env)
{
	char	*str;

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
				no_pipe(str, env);
			add_history(str);
		}
	}
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
