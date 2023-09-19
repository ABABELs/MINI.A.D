/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:32:05 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/19 13:40:24 by aabel            ###   ########.fr       */
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

//ajout **path
//ajout *root_path
static void	no_pipe(const char *str)
{
	t_crust		*crust;
	char		**tab;

	crust = malloc(sizeof(t_crust));
	crust->lst_cmd = malloc(sizeof(t_mantle));
	if (!crust || !crust->lst_cmd)
		return ;
	crust->pipe = ft_pipecount((char *)str);
	crust->input = (char *)str;
	crust->path = ft_split(getenv("PATH"), ':');
	crust->root_path = getenv("HOME");
	tab = ft_minisplit(crust->input);
	if (!tab)
		return ;
	ft_alloc_mantle(tab, crust->lst_cmd);
	ft_type_set(crust->lst_cmd);
	remove_quotes(crust->lst_cmd);
	ft_joincmd(crust->lst_cmd);
	// print_core(crust->lst_cmd);
	pipe_or_not(crust);
}

//boucle infini, affiche le prompt et gère les arguments envoyer
void	ft_minishell(void)
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
				no_pipe(str);
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
	ft_minishell();
	return (0);
}

//faire un gentenv peso
//finir le split
