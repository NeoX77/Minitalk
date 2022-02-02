/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:23 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/02 16:10:36 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static char	g_sbinary[7];

void	get_binary(int i_signum)
{
	static	
	if (i_signum == SIGUSR1)
}

int	main(void)
{
	ft_putstr("The server pid is : ");
	ft_putnbr(getpid());
	ft_putchar('\n');:wq
	while (1)
	{
		signal(SIGUSR1, get_binary);
		signal(SIGUSR2, get_binary);
		pause();
	}
}
