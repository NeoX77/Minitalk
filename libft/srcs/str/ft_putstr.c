/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:42:46 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/04 17:59:18 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"
#include <unistd.h>

void	ft_putstr(const char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
}
