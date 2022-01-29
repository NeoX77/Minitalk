/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/29 17:16:49 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int args, char **argv)
{
	(void)argv;
	if (args != 3)
	{
		ft_putstr("Usage: ./client \"pid\" \"message\"");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
