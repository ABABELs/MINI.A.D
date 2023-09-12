/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandan <dcandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:36:38 by dcandan           #+#    #+#             */
/*   Updated: 2022/11/15 13:36:38 by dcandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		a;

	a = 0;
	if (s == 0 || f == 0)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == 0)
		return (0);
	while (s[a])
	{
		str[a] = f(a, s[a]);
		a++;
	}
	str[a] = '\0';
	return (str);
}
