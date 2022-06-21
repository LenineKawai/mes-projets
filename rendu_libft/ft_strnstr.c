/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:07:13 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/08 14:11:28 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*nee)
		return ((char *)hay);
	while (i < len && hay[i])
	{
		j = 0;
		while (((char *)hay)[i + j] == ((char *)nee)[j] && i + j < len)
		{
			if (nee[j + 1] == '\0')
			{
				return ((char *)&hay[i]);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}
