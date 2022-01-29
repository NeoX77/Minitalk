/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:33:12 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/08 18:47:51 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buffer;

	if (!s)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (buffer == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		buffer[i] = f(i, s[i]);
	buffer[i] = '\0';
	return (buffer);
}
