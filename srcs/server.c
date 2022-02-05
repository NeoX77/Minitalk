/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:16 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/05 19:05:46 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/headers/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static void	ft_fill_binary(char *s_binary, int i_index, int i_signum)
{
	if (i_signum == SIGUSR1)
		s_binary[i_index] = '0';
	else if (i_signum == SIGUSR2)
		s_binary[i_index] = '1';
}

static char	*ft_fill_buffer(char *s_buffer, char *s_binary)
{
	char	*s_tmp;
	char	c_tmp[2];

	c_tmp[0] = ft_atoi_base(s_binary, "01");
	c_tmp[1] = '\0';
	s_tmp = s_buffer;
	s_buffer = ft_strjoin(s_tmp, c_tmp);
	free(s_tmp);
	return (s_buffer);
}

void	get_message(int i_signum)
{
	static int	i_bytes = 0;
	static char	s_binary[8] = {'0', '0', '0', '0', '0', '0', '0', '\0'};
	static char	*s_buffer;

	if (s_buffer == NULL)
	{
		s_buffer = malloc(sizeof(char));
		if (s_buffer == NULL)
			return ;
		s_buffer[0] = '\0';
	}
	if (i_bytes < 7)
		ft_fill_binary(s_binary, i_bytes, i_signum);
	i_bytes++;
	if (i_bytes == 7)
	{
		s_buffer = ft_fill_buffer(s_buffer, s_binary);
		i_bytes = 0;
	}
	if (ft_atoi_base(s_binary, "01") == '\0')
	{
		ft_printf("%s\n", s_buffer);
		free(s_buffer);
		s_buffer = 0
		s_buffer = 0;;
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
