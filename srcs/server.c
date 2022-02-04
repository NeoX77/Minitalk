/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:16 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/04 20:23:56 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/headers/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	get_message(int i_signum)
{
	static int	i_bytes = -1;

	if (++i_bytes < 7)
	{
		if (i_signum == SIGUSR1)
			ft_putchar('0');
		else if (i_signum == SIGUSR2)
			ft_putchar('1');
	}
	else
	{
		ft_putchar('\n');
		i_bytes = -1;
	}
}

int	main(void)
{
	ft_putstr("The pid is : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (1)
		pause();
}
