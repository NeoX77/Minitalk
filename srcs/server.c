/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:17:48 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/13 18:06:42 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_vars
{
	int		received;
	int		bytes;
	int		pid;
	char	*buffer;
	char	c;
}	t_vars;

t_vars	g_svars;

static int	ft_fill_buffer(void)
{
	char	*buffertmp;
	char	ctmp[2];

	if (g_svars.buffer == NULL)
	{
		g_svars.buffer = malloc(sizeof(char));
		if (g_svars.buffer == NULL)
			return (0);
		g_svars.buffer[0] = '\0';
	}
	ctmp[0] = g_svars.c;
	ctmp[1] = '\0';
	buffertmp = g_svars.buffer;
	g_svars.buffer = ft_strjoin(buffertmp, ctmp);
	free(buffertmp);
	return (1);
}

static void	ft_check_infos(siginfo_t *info)
{
	if (g_svars.pid == 0 || g_svars.pid != info->si_pid)
	{
		g_svars.received = 0;
		g_svars.bytes = 0;
		free(g_svars.buffer);
		g_svars.buffer = 0;
		g_svars.c = 0;
		g_svars.pid = info->si_pid;
	}
}

static void	close_server(int signum)
{
	(void)signum;
	if (g_svars.pid)
		kill(g_svars.pid, SIGUSR2);
	ft_printf("Good bye!\n");
	exit(EXIT_SUCCESS);
}

static void	get_message(int signum, siginfo_t *info, void *context)
{
	(void)context;
	ft_check_infos(info);
	g_svars.c |= (signum == SIGUSR2);
	if (++g_svars.bytes == 8)
	{
		if (ft_fill_buffer() && g_svars.c == 0)
		{
			g_svars.received = 1;
			ft_printf("%s\n", g_svars.buffer);
			free(g_svars.buffer);
			g_svars.buffer = 0;
			kill(info->si_pid, SIGUSR2);
		}
		g_svars.bytes = 0;
		g_svars.c = 0;
	}
	else
		g_svars.c <<= 1;
	if (g_svars.received == 0)
		kill(info->si_pid, SIGUSR1);
	g_svars.received = 0;
}

int	main(void)
{
	struct sigaction	s_action;

	g_svars.pid = 0;
	g_svars.buffer = 0;
	sigemptyset(&s_action.sa_mask);
	ft_printf("Take my pid : %i, and send me a message!\n", getpid());
	s_action.sa_sigaction = &get_message;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	signal(SIGINT, close_server);
	while (1)
		pause();
	return (0);
}
