/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:22:26 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/08 10:34:31 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_number_size(int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i ++;
	}
	return (i);
}

static char	*ft_put_in_tab(long int nbr, int i)
{
	int		size;
	char	*number;

	number = malloc((ft_number_size(nbr) + 2) * sizeof(char));
	if (!number)
		return (malloc(0));
	size = ft_number_size(nbr);
	if (i == 1)
	{
		number[0] = '-';
		number[size + 1] = 0;
		size += 1;
	}
	else
		number[size] = 0;
	while (i < size)
	{
		number[size - 1] = nbr % 10 + 48;
		nbr /= 10;
		size --;
	}
	return (number);
}

char	*ft_itoa(int nb)
{
	char		*number;
	long int	minus;
	long int	nbr;

	minus = -1;
	nbr = nb;
	number = NULL;
	if (nbr < 0)
	{
		nbr *= minus;
		number = ft_put_in_tab(nbr, 1);
	}
	else if (nbr > 0)
	{
		number = ft_put_in_tab(nbr, 0);
	}
	else if (nbr == 0)
	{
		number = malloc(2 * sizeof(char));
		number[0] = '0';
		number[1] = '\0';
	}
	return (number);
}
