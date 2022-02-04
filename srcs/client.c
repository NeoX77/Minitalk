/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:45:49 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/04 17:51:37 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/headers/libft.h"
#include <stdio.h>
#include <signal.h>

int	main(int args, char **argv)
{
	int		i_pid;
	char	*s_message;

	if (args != 3)
	{
		ft_putstr("Usage: ./client [pid] [message]\n");
		return (1);
	}
	i_pid = ft_atoi(argv[1]);
	if (i_pid <= 0)
	{
		ft_putstr("The pid seems strange !\n");
		return (1);
	}
}
