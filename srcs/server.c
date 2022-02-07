/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:16 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/07 17:20:00 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static char	*ft_fill_buffer(char *s_buffer, char c_char)
{
	char	*s_tmp;
	char	c_tmp[2];

	if (s_buffer == NULL)
	{
		s_buffer = malloc(sizeof(char));
		if (s_buffer == NULL)
			return (NULL);
		s_buffer[0] = '\0';
	}
	c_tmp[0] = c_char;
	c_tmp[1] = '\0';
	s_tmp = s_buffer;
	s_buffer = ft_strjoin(s_tmp, c_tmp);
	free(s_tmp);
	return (s_buffer);
}

static void	get_message(int i_signum)
{
	static int				i_bytes = 0;
	static unsigned char	uc_char = 0;
	static char				*s_buffer;

	uc_char |= (i_signum == SIGUSR2);
	if (++i_bytes == 8)
	{
		i_bytes = 0;
		s_buffer = ft_fill_buffer(s_buffer, uc_char);
		if (uc_char == 0)
		{
			ft_putstr(s_buffer);
			ft_putchar('\n');
			free(s_buffer);
			s_buffer = 0;
		}
		uc_char = 0;
	}
	else
		uc_char <<= 1;
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
	return (0);
}
