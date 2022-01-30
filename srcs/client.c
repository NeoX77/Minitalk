/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/30 17:46:38 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int args, char **argv)
{
	(void)argv;
	if (args != 3)
	{
		ft_putstr("Usage: ./client \"pid\" \"message\"\n");
		exit(EXIT_FAILURE);
	}
	kill(ft_atoi(argv[1]), SIGUSR1);
	kill(ft_atoi(argv[1]), SIGUSR2);
	kill(ft_atoi(argv[1]), SIGQUIT);
	exit(EXIT_SUCCESS);
}
