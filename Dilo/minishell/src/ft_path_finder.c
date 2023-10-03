/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:09:10 by dilovancand       #+#    #+#             */
/*   Updated: 2023/10/03 13:44:25 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//calcul la taille du $path pour le malloc par la suite
static int	ft_path_size(char *str)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (str[a] && str[a] != '$')
		a++;
	if (str[a] == '$')
	{
		a++;
		while (str[a + b] >= '!' && str[a + b] <= '~' && str[a + b])
		{
			if (str[a + b] == '$' || str[a + b] == 34 || str[a + b] == 39
				|| check_dollars(str[a + b]) != 0)
				return (b);
			b++;
		}
		return (b);
	}
	return (0);
}

//copie le $path pour getenv
static char	*ft_preprint(char *str, int b, int a)
{
	char	*tmp;
	int		c;

	c = 1;
	tmp = malloc(sizeof(char) * (b + 1));
	if (!tmp)
		return (NULL);
	while ((c - 1) != b && check_dollars(str[a + c]) == 0)
	{
		tmp[c - 1] = str[a + c];
		c++;
	}
	tmp[c] = '\0';
	return (tmp);
}

//sépare la chaine de caractère en deux
static void	ft_split_path(char *str, t_pathport **pathing, int a)
{
	int	b;
	int	c;

	b = a + (ft_path_size(str));
	c = 0;
	(*pathing)->string1 = malloc(sizeof(char) * (a + 1));
	if (!(*pathing)->string1)
		return ;
	while (c < a)
	{
		(*pathing)->string1[c] = str[c];
		c++;
	}
	c = ft_path_strlen(str, b);
	(*pathing)->string2 = malloc(sizeof(char) * (c + 1));
	if (!(*pathing)->string2)
		return ;
	c = 0;
	while (str[b + c])
	{
		(*pathing)->string2[c] = str[b + c];
		c++;
	}
}

/* 
	coupe la chaine de caractère en deux isole le $PATH puis 
	recolle la chaine en ajoutant le chemin d'accès à la place 
	de $PATH ou équivalent du moment qu'il existe dans l'ordinateur
*/
static char	*ft_return_path(t_pathport *pathing, int a, t_crust *crust)
{
	int			b;

	if (pathing->final[a] == '$')
	{	
		if (check_dollars(pathing->final[a + 1]) == 1)
			return (pathing->final);
		b = ft_path_size(pathing->final);
		pathing->pathifik = ft_preprint(pathing->final, b, a);
		pathing->pathion = ft_getenv(crust, pathing->pathifik);
		if (!pathing->pathion)
			return (NULL);
		ft_split_path(pathing->final, &pathing, a);
		pathing->final = ft_strjoin(pathing->string1, pathing->pathion);
		pathing->final = ft_strjoin(pathing->final, pathing->string2);
		(free(pathing->string1), free(pathing->string2));
	}
	return (pathing->final);
}

/*
	récupère une chaine de charactère contenant un $,
	ainsi qu'une struct qui permet le découpage de la string,
	la fonction parcours la string tout en répérant les quotes,
	si le $ est dans une single quote la fonction l'ignore
	sinon va chercher la variable d'environnement et la place dans la string
*/
char	*ft_print_path(char *str, t_pathport *path, t_crust *crust)
{
	int			a;

	a = -1;
	path->final = str;
	path->f = 0;
	path->c = 0;
	while (path->final[++a])
	{
		if (path->f == 1 && path->final[a] == path->c)
		{
			path->f = 0;
			path->c = 0;
		}
		else if (path->f == 0 && (path->final[a] == 34 || path->final[a] == 39))
		{
			path->c = path->final[a];
			path->f = 1;
		}
		if (path->final[a] == '$')
			if (path->c != 39)
				path->final = ft_return_path(path, a, crust);
		if (!path->final)
			return (NULL);
	}
	return (path->final);
}
