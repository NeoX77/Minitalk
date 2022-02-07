/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:45:49 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/07 10:41:56 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void	ft_send_char_to_server(char c_char, int i_pid)
{
	int	byte;

	byte = 7;
	while (byte >= 0)
	{
		if (c_char >> byte & 1)
			kill(i_pid, SIGUSR2);
		else
			kill(i_pid, SIGUSR1);
		byte--;
		usleep(1000);
	}
}

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
	s_message = argv[2];
	while (*s_message != '\0')
		ft_send_char_to_server(*s_message++, i_pid);
	ft_send_char_to_server('\0', i_pid);
	return (0);
}
