/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:50:23 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/04 06:17:06 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/headers/libft.h"
#include <stdlib.h>
#include <signal.h>

void	get_binary(int i_signum)
{
	static int	i_bytes = 0;
	static char	*s_binary;
	char		*s_tmp;
	char		*s_byte_tmp;

	if (s_binary == NULL)
	{
		s_binary = malloc(sizeof(char));
		if (s_binary == NULL)
			return ;
		s_binary[0] = '\0';
	}
	if (i_bytes < 7)
	{
		s_byte_tmp = malloc(sizeof(char) * 2);
		if (s_byte_tmp == NULL)
			return ;
		if (i_signum == SIGUSR1)
			s_byte_tmp[0] = '0';
		else if (i_signum == SIGUSR2)
			s_byte_tmp[0] = '1';
		s_byte_tmp[1] = '\0';
		s_tmp = s_binary;
		s_binary = ft_strjoin(s_tmp, s_byte_tmp);
		free(s_tmp);
		free(s_byte_tmp);
		i_bytes++;
	}
	else
	{
		ft_printf("%s\n", s_binary);
		i_bytes = 0;
	}
}

int	main(void)
{
	ft_putstr("The server pid is : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, get_binary);
	signal(SIGUSR2, get_binary);
	while (1)
		pause();
}
