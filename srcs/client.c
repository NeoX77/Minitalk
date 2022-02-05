/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:45:49 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/05 19:03:55 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/headers/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void	ft_send_char_to_server(char c_char, int i_pid)
{
	int		i;
	char	*s_tmp;
	char	*s_binary;

	s_binary = ft_itoa_base(c_char, "01");
	while (ft_strlen(s_binary) < 7)
	{
		s_tmp = s_binary;
		s_binary = ft_strjoin("0", s_tmp);
		free(s_tmp);
	}
	i = 0;
	while (s_binary[i] != '\0')
	{
		if (s_binary[i] == '0')
			kill(i_pid, SIGUSR1);
		else if (s_binary[i] == '1')
			kill(i_pid, SIGUSR2);
		i++;
		usleep(250);
	}
	free(s_binary);
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
