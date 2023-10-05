/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:15 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/05 20:54:29 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <curses.h>
// # include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>

# define CWD_SIZE 64

# define TRUE 1
# define FALSE 0

# define ERROR 1
# define ALL_G 0

int	g_mini_sig;

//pour déclarer le type
typedef enum s_type
{
	NO,
	CMD,
	ARG,
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
	char	*pathed;
	int		infile;
	int		outfile;
	int		fdp[2];
	pid_t	child;
	int		error;
	int		to_delete;
	int		exit_code;
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
	char		**path;
	char		*root_path;
	int			syntax_error;
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

//lanch
void	ft_minishell(char **env);

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
int		ft_alloc_mantle(char **tab, t_mantle *mantle, t_crust *crust);

//parsing
int		ft_pipecount(char *str);
int		is_quote_close(char *str);
int		find_char(char	*tab, char c);
void	print_core(t_mantle *mantle);
int		ft_ispth(char *str);
int		ft_isquote(char *str);
int		ft_after_redir(t_mantle *mantle);
char	**array_dup(char **array);

//redirection
int		ft_strcmp(const char *s1, const char *s2);
void	ft_type_set(t_mantle *mantle);

//path handler
int		check_dollars(char str);
char	*ft_print_path(char *str, t_pathport *path, t_crust *crust);
int		ft_path_strlen(char *str, int b);

//signal handler
void	ft_sigint_handler(int si);
void	ft_sigquit_handler(int si);
void	ft_signal_in_fork(void);
void	ft_signal(void);
void	sig_handler(int sig);

//pipe
void	pipe_or_not(t_crust *crust);
void	join_the_pipe(t_crust *crust);
void	run_my_child(t_core *cmd, t_crust *crust);
void	lanch_pipe(t_crust *crust);
void	exec_my_pipe(t_core *core, t_crust *crust);
void	close_fd(t_core *core);
t_core	*find_prev(t_list *list);
void	not_used_pipe(t_crust *crust);
int		path_in_cmd(t_crust *crust, t_core *core);
void	print_lst_parsing(t_list *lst_parsing);
void	remove_pipe(t_crust *crust);
void	wait_all_process(t_crust *crust);
void	close_all_fd(t_crust *crust);
void	ft_message(char *msg_0, char *token, char *msg_1);
int		ft_slash(char *str);
int		ft_count_cmds(t_crust *crust);
void	pipe_syntax_checker(t_crust *crust, t_list *list);

//exit_code
void	last_exit_code(t_list *list);

//builtins
void	cd(t_core *core, t_crust *crust);
int		arg_good(t_core *core, t_crust *crust);
void	set_pwds(t_crust *crust, char *oldpwd);
void	ft_echo(t_core *core);
void	env(t_crust *crust, t_core *core);
void	ft_exit(t_core *core);
void	ft_exit_no_arg(t_core *core);
void	ft_exit_args(t_core *core);
void	ft_exit_arg(void);
int		is_numeric_arg(char *str);
void	pwd(t_core *core);
void	unset(t_core *core, t_crust *crust);
char	**remove_env_var(char **env, int index);
int		find_env_var(t_crust *crust, char *find_env);
int		ft_arraylen(char **array);
int		ft_isbuiltins(t_core *core);
void	exec_my_builtins(char *cmd, t_core *core, t_crust *crust);
void	export(t_crust *crust, t_core *core);
int		ft_check_syntax(char *str);
int		ft_export_char(char c, int i);
int		ft_check_env(t_crust *crust, char *find_env);
char	**array_join(char **array, char *line);
char	*check_tilde(t_core *core, t_crust *crust, char *pwd, char *path);
void	poop(t_core *core, t_crust *crust);
void	normed(int *is_syntax, t_core *core, int i);
int		ft_env_exist(t_crust *crust, char *env);
void	ft_export_no_args(t_crust *crust, t_core *core);
char	**ft_sort_env(char **env, char **new);
void	ft_env_no_args(char **env, t_core *core);

//print error
char	*ft_ministrncpy(char *dest, char *src, int a, int b);
int		ft_print_msg(int a, char *str);

//open
int		ft_open_fd(t_mantle *mantle);
t_core	*ft_find_cmd(t_list *list);
int		ft_redir_error(char *str, t_list *list, int error);

//free
void	ft_free_array(char **array);
void	node_to_del(t_mantle *lst_cmd);
void	remove_node(t_list **head, t_list *node_to_remove);
int		is_node_to_del(t_list *lst);

//herdoc
void	ft_heredoc(t_mantle *mantle);
void	quit_heredoc(int sig);
void	ft_readdoc(t_core *core, t_list *list);

//env
char	*ft_getenv(t_crust *crust, char *find_env);
void	env_var_expension(t_crust *crust, t_list *lst_cmd);
int		is_env_var(t_core *core);
char	*cut_to_getenv(int *i, char *tmp, t_core *core, t_crust *crust);
void	env_to_string(t_crust *crust, t_core *core);
char	*ft_strjoin_char(char *s1, char s2);
int		ft_is_envchar(int c);
int		is_quoted_and_who(char	*input, int goal);
int		ft_strlen_int(char *str);

#endif