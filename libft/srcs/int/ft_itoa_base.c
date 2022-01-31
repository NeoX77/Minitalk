/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:19:06 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/31 16:42:00 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

//Know how many chars takes n
static int	ft_sizebuffer(long int n)
{
	int	chars;

	if (n == 0)
		return (1);
	chars = 0;
	if (n < 0)
	{
		n = -n;
		chars++;
	}
	while (n > 0)
	{
		n /= 10;
		chars++;
	}
	return (chars);
}

static int	is_base_correct(char *base)
{
	int	i;
	int	n;

	i = 0;
	if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
		return (0);
	while (base[i] != '\0')
	{
		n = 1;
		while (base[i + n] != '\0')
		{
			if (base[i + n] == '+' || base[i + n] == '-'
				|| ft_isspace(base[i + n]) || base[i + n] == base[i])
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

static int	ft_get_base_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0' && base[i] != c)
		i++;
	return (i);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char		*s_nbr;
	int			i_basesize;
	long int	li_nbr;

	i_basesize = ft_strlen(base);
	if (i_basesize <= 1 || !is_base_correct(base))
		return (ft_strdup("0"));
	li_nbr = nbr;
	nbr = ft_sizebuffer(li_nbr);
	s_nbr = malloc(sizeof(char) * (nbr + 1));
	if (s_nbr == NULL)
		return (NULL);
	s_nbr[nbr--] = '\0';
	if (li_nbr == 0)
		s_nbr[nbr] = base[0];
	if (li_nbr < 0)
	{
		s_nbr[0] = '-';
		li_nbr = -li_nbr;
	}
	while (li_nbr > 0)
	{
		s_nbr[nbr--] = (li_nbr % i_basesize) + base[0];
		li_nbr /= i_basesize;
	}
	return (s_nbr);
}

#include <stdio.h>

int	main(int args, char **argv)
{
	(void)args;
	printf(": %s\n", ft_itoa_base(ft_atoi(argv[1]), argv[2]));
}
