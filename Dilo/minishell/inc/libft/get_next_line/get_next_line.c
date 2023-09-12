/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:41:37 by dcandan           #+#    #+#             */
/*   Updated: 2023/07/27 20:18:10 by dilovancand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char *str)
{	
	if (str)
	{
		free(str);
		str = 0;
		return (NULL);
	}
	return (NULL);
}

char	*cutsr(char *sstr)
{
	int		save;
	char	*cutedstr;

	save = 0;
	while (sstr[save] != '\n' && sstr[save])
		save++;
	if (sstr[save] == '\n')
		save++;
	cutedstr = malloc(sizeof(char) * (save + 1));
	if (!cutedstr)
		return (free_all(sstr));
	save = -1;
	while (sstr[++save] != '\n' && sstr[save])
		cutedstr[save] = sstr[save];
	if (sstr[save] == '\n')
	{
		cutedstr[save] = sstr[save];
		save++;
	}
	cutedstr[save] = '\0';
	if (cutedstr[0] == '\0')
		return (free_all(cutedstr));
	return (cutedstr);
}

char	*nextline(char *sstr)
{
	int		nice;
	char	*nextstr;
	int		very;

	nice = 0;
	very = 0;
	while (sstr[nice] != '\n' && sstr[nice])
		nice++;
	if (sstr[nice] == '\n')
		nice++;
	if (!sstr[nice])
		return (free_all(sstr));
	nextstr = malloc(sizeof(char) * (ft_strlen3(sstr) - nice + 1));
	if (!nextstr)
		return (free_all(sstr));
	while (sstr[nice + very])
	{
		nextstr[very] = sstr[very + nice];
		very++;
	}
	free_all(sstr);
	sstr = 0;
	nextstr[very] = '\0';
	return (nextstr);
}

static char	*readlinentm(int fd, char *sstr, char *buf)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
			return (free_all(buf));
		buf[ret] = '\0';
		sstr = ft_strjoin3(sstr, buf);
		if (ft_strchr3(sstr, '\n'))
			break ;
	}
	return (sstr);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*sstr = NULL;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buf, 0) < 0))
	{
		free(sstr);
		sstr = 0;
		return (sstr);
	}
	str = NULL;
	sstr = readlinentm(fd, sstr, buf);
	if (!sstr)
		return (free_all(sstr));
	str = cutsr(sstr);
	if (!str)
		sstr = 0;
	if (!sstr)
		return (0);
	sstr = nextline(sstr);
	return (str);
}
