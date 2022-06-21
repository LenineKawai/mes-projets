/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:30:19 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/15 17:14:28 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)

{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (str[i])
	{
		if (str[i] == chr)
		{
			return ((char *)&str[i]);
		}
		i ++;
	}
	if (chr == 0)
	{
		return ((char *)&str[i]);
	}
	return (0);
}
