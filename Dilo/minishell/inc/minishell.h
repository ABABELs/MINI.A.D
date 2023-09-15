/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:15 by dilovancand       #+#    #+#             */
/*   Updated: 2023/09/15 23:49:53 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

//pour déclarer le type
typedef enum s_type
{
	NO,
	CMD,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	APPEND,
	HERDOC,
	FD,
}			t_type;

//contient chaque mot ainsi que son attribut, noyau du parsing
typedef struct s_core
{
	char	*str;
	char	**tab;
	int		infile;
	int		outfile;
	int		fdp[2];
	pid_t	child;
	int		error;
	t_type	type;
}			t_core;

//contient le début de la liste chainée et le nombre de liste
typedef struct s_mantle
{
	t_list	*first;
	int		list_nb;
}			t_mantle;

//couche exterieur du parsing contient 
typedef struct s_crust
{
	char		*for_print;
	char		*input;
	char		**env;
	char		*path;
	int			pipe;
	t_mantle	*lst_cmd;
}				t_crust;

//struct qui gère les $path
typedef struct s_pathport
{
	char	*final;
	char	*pathifik;
	char	*pathion;
	char	*string1;
	char	*string2;
	int		f;
	char	c;
}			t_pathport;

//cmd cleaner
void	ft_joincmd(t_mantle *mantle);
char	*ft_cmdisgood(char *str);

//minisplit
char	**ft_minisplit(char const *s);
int		ft_redir_count(char *s, char c, int a, int tab_nb);
int		ft_count_tab(char *s, int a, int tab_nb);
int		is_sep(char c);
void	cpy(char *tab, char *s, int letters, int d);
char	**free_all(char **tab, int a);

//list alloc
void	ft_alloc_mantle(char **tab, t_mantle *mantle);

//parsing
int		ft_pipecount(char *str);
int		is_quote_close(char *str);
int		find_char(char	*tab, char c);
void	print_core(t_mantle *mantle);
int		ft_ispth(char *str);
int		ft_isquote(char *str);
int		ft_after_redir(t_mantle *mantle);

//redirection
int		ft_strcmp(const char *s1, const char *s2);
void	ft_type_set(t_mantle *mantle);

//path handler
int		check_dollars(char str);
char	*ft_print_path(char *str, t_pathport *path);
int		ft_path_strlen(char *str, int b);

//signal handler
void	ft_sigint_handler(int si);
void	ft_sigquit_handler(int si);

//pipe
void	pipe_or_not(t_crust *crust);
void	join_the_pipe(t_crust *crust);
void	run_my_child(t_core *cmd, t_crust *crust, t_list *list);
void	lanch_pipe(t_crust *crust);

//builtins
void	cd(t_core *core);
void	ft_echo(t_core *core);
void	env(t_crust *crust);
void	exit_shell(t_core *core);
void	pwd(t_crust *crust);
void	unset(t_core *core, t_crust *crust);
char	**remove_env_var(char **env, int index);
int		find_env_var(char **env, char *var);
int		ft_isbuiltins(t_core *core);
void	exec_my_builtins(char *cmd, t_core *core, t_crust *crust);
void	export(t_core *core, t_crust *crust);

//print error
char	*ft_ministrncpy(char *dest, char *src, int a, int b);
int		ft_print_msg(int a, char *str);

#endif