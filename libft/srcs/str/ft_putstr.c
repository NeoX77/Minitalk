/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:42:46 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/08 20:05:33 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_putstr(const char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
	ft_putchar('\n');
}
