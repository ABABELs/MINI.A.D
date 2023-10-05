/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:38:25 by arthurabel        #+#    #+#             */
/*   Updated: 2023/10/05 13:27:27 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_numeric_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_exit_arg(void)
{
	printf("exit\n");
	exit(0);
}

void	ft_exit_args(t_core *core)
{
	printf("exit\n");
	if (is_numeric_arg(core->tab[1]))
	{
		exit(ft_atoi(core->tab[1]));
	}
	else
	{
		ft_message("minishell: exit: ",
			core->tab[1], "numeric argument required");
		exit(255);
	}
}

void	ft_exit_no_arg(t_core *core)
{
	printf("exit\n");
	ft_putstr_fd("minishell: exit: too many arguments", 2);
	core->exit_code = 1;
}

void	ft_exit(t_core *core)
{
	int	nb_arg;

	nb_arg = ft_arraylen(core->tab);
	if (nb_arg == 1)
		ft_exit_arg();
	else if (nb_arg == 2)
		ft_exit_args(core);
	else
		ft_exit_no_arg(core);
}
