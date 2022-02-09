/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:01:18 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/09 13:57:35 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_info
{
	int		serverpid;
	char	*str;
}	t_info;

typedef struct s_vars
{
	int				received;
	int				bytes;
	char			*buffer;
	unsigned char	uc;
}	t_vars;

#endif
