/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:23 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/29 17:33:15 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(void)
{
	int	i_pid;

	i_pid = getpid();
	ft_putstr("The server pid is : ");
	ft_putnbr(i_pid);
	ft_putchar('\n');
	while (1)
	{
		ft_printf("prout");
		pause();
	}
}
