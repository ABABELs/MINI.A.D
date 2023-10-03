/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/03 14:09:44 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	récupère la liste chainée contenant les cores les parcours
	retire les quotes qui ne sont pas dans d'autres quotes
	dans la chaine de charactère
*/
static void	remove_quotes(t_mantle *mantle)
{
	t_list	*list;
	t_core	*core;
	char	*str;

	list = mantle->first;
	while (list)
	{
		core = (t_core *)list->content;
		if (!core->str)
			return ;
		if (ft_isquote(core->str) == 1)
		{
			str = ft_cmdisgood(core->str);
			free(core->str);
			core->str = str;
		}
		list = list->next;
	}
}

static void	no_pipe(const char *str, char **env)
{
	t_crust		*crust;
	char		**tab;
	char		*get_env;

	crust = malloc(sizeof(t_crust));
	crust->lst_cmd = malloc(sizeof(t_mantle));
	crust->lst_cmd->first = NULL;
	if (!crust || !crust->lst_cmd)
		return ;
	crust->input = (char *)str;
	crust->env = array_dup(env);
	get_env = ft_getenv(crust, ft_strdup("PATH"));
	crust->path = ft_split(get_env, ':');
	free(get_env);
	tab = ft_minisplit(crust->input);
	crust->root_path = ft_getenv(crust, ft_strdup("HOME"));
	if (!tab || !tab[0])
		return ;
	(ft_alloc_mantle(tab, crust->lst_cmd, crust), ft_type_set(crust->lst_cmd));
	if (ft_after_redir(crust->lst_cmd) == -1)
		return ;
	ft_heredoc(crust->lst_cmd);
	(remove_quotes(crust->lst_cmd), ft_joincmd(crust->lst_cmd));
	(ft_open_fd(crust->lst_cmd), join_the_pipe(crust));
	pipe_or_not(crust);
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
	(void)env;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, ft_sigquit_handler);
	ft_minishell(env);
	return (0);
}

//supprimer les maillon vide
//ouvrir les fd
//mettre en place heredoc
//faire un gentenv perso
