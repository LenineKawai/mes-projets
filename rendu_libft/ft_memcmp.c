/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:39:37 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/08 12:03:06 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)str1)[i] == ((unsigned char *)str2)[i])
		i ++;
	if (i == n)
	{
		return (0);
	}
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
