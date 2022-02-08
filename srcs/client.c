/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:45:49 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/08 11:21:05 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void	handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("The message has been received !\n");
		exit(EXIT_SUCCESS);
	}
	else
		return ;
}

static void	ft_send_char_to_server(char c, int serverpid)
{
	int	byte;

	byte = 7;
	while (byte >= 0)
	{
		if (c >> byte & 1)
		{
			if ((kill(serverpid, SIGUSR2)) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if ((kill(serverpid, SIGUSR1)) == -1)
				exit(EXIT_FAILURE);
		}
		byte--;
		pause();
	}
}

int	main(int args, char **argv)
{
	int		serverpid;
	char	*str;

	if (args != 3)
	{
		ft_putstr("Usage: ./client [pid] [message]\n");
		return (1);
	}
	serverpid = ft_atoi(argv[1]);
	if (serverpid <= 0)
	{
		ft_putstr("The pid seems strange !\n");
		return (1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	str = argv[2];
	while (*str != '\0')
		ft_send_char_to_server(*str++, serverpid);
	ft_send_char_to_server('\0', serverpid);
	return (0);
}
