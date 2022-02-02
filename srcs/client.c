/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/02 16:10:41 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_send_char_to_server(char c_char, int i_serverpid)
{
	char	*s_binary;

	s_binary = ft_itoa_base(c_char, "01");
	while ()
	{
		:wq

	}
}

int	main(int args, char **argv)
{
	char	*s_str;

	if (args != 3)
	{
		ft_putstr("Usage: ./client \"pid\" \"message\"\n");
		exit(EXIT_FAILURE);
	}
	s_str = argv[2];
	while (*s_str != '\0')
	{
		ft_send_char_to_server(*s_str, ft_atoi(argv[1]));
		s_str++;
//		pause();
	}
	exit(EXIT_SUCCESS);
}
