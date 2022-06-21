/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:06:33 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/09 10:28:23 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	chr;

	i = ft_strlen(str);
	chr = (char)c;
	while (i >= 0)
	{
		if (str[i] == chr)
		{
			return ((char *)&str[i]);
		}
		i --;
	}
	if (chr == 0)
	{
		return ((char *)&str[i]);
	}
	return (0);
}
