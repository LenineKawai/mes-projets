/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:37:46 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/22 14:51:40 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static int	ft_iswhite(char str)
{
	int	i;

	i = 0;
	if ((str >= 9 && str <= 13) || (str == 32))
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
	int				i;
	long long int	nb;
	long long int	minus;

	i = 0;
	nb = 0;
	minus = 1;
	while (((char *)str)[i] && ft_iswhite(str[i]) == 1)
		i++;
	if (((char *)str)[i] == '-' || ((char *)str)[i] == '+')
	{
		if (((char *)str)[i] == '-')
			minus = -1;
		i++;
	}
	while (((char *)str)[i] && ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (minus * nb);
}
