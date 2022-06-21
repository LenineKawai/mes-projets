/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:59:26 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/10 16:53:21 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{		
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	dst[i] = '\0';
	return (i + (ft_strlen(src) - j));
}
