/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:32:43 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/23 09:24:09 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

int	ft_nbr_char_ct(long long int nb, char *base_to)
{
	int	i;
	int	t;

	i = 0;
	t = ft_strlen(base_to);
	if (nb == 0)
		return (1);
	if (nb < 0)
		i ++;
	while (nb != 0)
	{
		nb /= t;
		i ++;
	}
	return (i);
}

int	ft_putnbr_fd(int nb, int fd, int ct)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ct += ft_putchar_fd('-', fd, 0);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd, 0);
		ft_putnbr_fd(nbr % 10, fd, 0);
	}
	if (nbr <= 9)
	{
		ft_putchar_fd(nbr + 48, fd, 0);
	}
	ct = ft_nbr_char_ct(nb, "0123456789");
	return (ct);
}

int	ft_putchar_fd(char c, int fd, int ct)
{
	ct = write(fd, &c, 1);
	return (ct);
}

int	ft_putstr_fd(char *str, int fd, int ct)
{
	int	i;

	i = 0;
	if (!str)
	{
		ct = ft_putstr_fd("(null)", 1, 0);
		return (6);
	}
	while (str[i])
	{
		ct += ft_putchar_fd(str[i], fd, 0);
		i ++;
	}
	return (ct);
}
