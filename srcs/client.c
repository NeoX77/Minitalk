/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/04 05:43:06 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/headers/libft.h"
#include <stdlib.h>
#include <signal.h>

static void	ft_send_char_to_server(char c_char, int i_pid)
{
	char	*s_tmp;
	char	*s_binary;

	s_binary = ft_itoa_base(c_char, "01");
	while (ft_strlen(s_binary) < 7)
	{
		s_tmp = s_binary;
		s_binary = ft_strjoin("0", s_tmp);
		free(s_tmp);
	}
	ft_printf("%s\n", s_binary);
	while (*s_binary != '\0')
	{
		if (*s_binary == '0')
			kill(i_pid, SIGUSR1);
		else if (*s_binary == '1')
			kill(i_pid, SIGUSR2);
		s_binary++;
		usleep(500);
	}
}

int	main(int args, char **argv)
{
	int		i_pid;
	char	*s_str;

	if (args != 3)
	{
		ft_putstr("Usage: ./client \"pid\" \"message\"\n");
		exit(EXIT_FAILURE);
	}
	i_pid = ft_atoi(argv[1]);
	s_str = argv[2];
	while (*s_str != '\0')
	{
		ft_send_char_to_server(*s_str, i_pid);
		s_str++;
	}
	ft_send_char_to_server('\0', i_pid);
	exit(EXIT_SUCCESS);
}
