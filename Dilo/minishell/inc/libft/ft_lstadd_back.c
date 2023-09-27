/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:23:00 by dcandan           #+#    #+#             */
/*   Updated: 2023/09/27 15:42:22 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	last = *lst;
// 	if (*lst)
// 	{
// 		last = ft_lstlast(*lst);
// 		last->next = new;
// 	}
// 	else
// 		*lst = new;
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		new->prev = 0;
		(*lst) = new;
	}
	else
	{
		new->prev = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
	}
}
