/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:37:02 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/07 12:48:29 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbr(int nbr)
{
	char	*s_nbr;

	s_nbr = ft_itoa(nbr);
	ft_putstr(s_nbr);
	free(s_nbr);
}
