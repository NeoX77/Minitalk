/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:23 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/30 17:59:32 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	toto(int i_signum)
{
	if (i_signum == SIGUSR1)
		printf("I received SIGUSR1 : %i\n", i_signum);
	else if (i_signum == SIGUSR2)
		printf("I received SIGUSR2 : %i\n", i_signum);
	else
		printf("coucou\n");
}

int	main(void)
{
	ft_putstr("The server pid is : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR2, toto);
		signal(SIGUSR1, toto);
		signal(SIGQUIT, toto);
		pause();
	}
}
