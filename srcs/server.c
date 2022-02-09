/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:17:48 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/09 13:52:59 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_vars	g_svars;

static void	*ft_fill_buffer(void)
{
	char	*buffertmp;
	char	ctmp[2];

	if (g_svars.buffer == NULL)
	{
		g_svars.buffer = malloc(sizeof(char));
		if (g_svars.buffer == NULL)
			return (NULL);
		g_svars.buffer[0] = '\0';
	}
	ctmp[0] = g_svars.uc;
	ctmp[1] = '\0';
	buffertmp = g_svars.buffer;
	g_svars.buffer = ft_strjoin(buffertmp, ctmp);
	free(buffertmp);
	return (NULL);
}

static void	get_message(int signum, siginfo_t *info, void *context)
{
	(void)context;
	g_svars.uc |= (signum == SIGUSR2);
	if (++g_svars.bytes == 8)
	{
		ft_fill_buffer();
		if (g_svars.uc == 0)
		{
			g_svars.received = 1;
			ft_printf("%s\n", g_svars.buffer);
			free(g_svars.buffer);
			g_svars.buffer = 0;
			if ((kill(info->si_pid, SIGUSR2)) == -1)
				exit(EXIT_FAILURE);
		}
		g_svars.bytes = 0;
		g_svars.uc = 0;
	}
	else
		g_svars.uc <<= 1;
	if (g_svars.received == 0)
		kill(info->si_pid, SIGUSR1);
	else
		g_svars.received = 0;
}

int	main(void)
{
	struct sigaction	s_action;

	g_svars.received = 0;
	g_svars.bytes = 0;
	g_svars.uc = 0;
	sigemptyset(&s_action.sa_mask);
	ft_printf("Take my pid : %i, and send me a message !\n", getpid());
	s_action.sa_sigaction = &get_message;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
		pause();
	return (0);
}
