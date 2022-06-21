/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:50:07 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/15 14:09:57 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(char str)
{
	int	i;

	i = 0;
	if ((str >= 9 && str <= 13)
		|| (str == 32))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	minus;

	i = 0;
	nb = 0;
	minus = 1;
	while (((char *)str)[i] && ft_iswhite(str[i]) == 1)
		i ++;
	if (((char *)str)[i] == '-' || ((char *)str)[i] == '+')
	{
		if (((char *)str)[i] == '-')
			minus = -1;
		i ++;
	}
	while (((char *)str)[i] && ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - 48;
		i ++;
	}
	return (minus * nb);
}
