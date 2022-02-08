/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:16 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/08 11:10:50 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static char	*ft_fill_buffer(char *buffer, char c)
{
	char	*tmp;
	char	c_tmp[2];

	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char));
		if (buffer == NULL)
			return (NULL);
		buffer[0] = '\0';
	}
	c_tmp[0] = c;
	c_tmp[1] = '\0';
	tmp = buffer;
	buffer = ft_strjoin(tmp, c_tmp);
	free(tmp);
	return (buffer);
}

static void	get_message(int signum, siginfo_t *info, void *context)
{
	static int				bytes = 0;
	static unsigned char	uc = 0;
	static char				*buffer;

	(void)context;
	uc |= (signum == SIGUSR2);
	if (++bytes == 8)
	{
		bytes = 0;
		buffer = ft_fill_buffer(buffer, uc);
		if (uc == 0)
		{
			ft_printf("%s\n", buffer);
			free(buffer);
			buffer = 0;
			if ((kill(info->si_pid, SIGUSR2)) == -1)
				exit(EXIT_FAILURE);
		}
		uc = 0;
	}
	else
		uc <<= 1;
	if ((kill(info->si_pid, SIGUSR1)) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("Hi ! My pid is : %i. Try to send me a message !\n", getpid());
	s_action.sa_sigaction = &get_message;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
		pause();
	return (0);
}
