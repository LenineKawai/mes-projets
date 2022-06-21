/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:38:34 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/23 10:41:52 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_char_unsigned(unsigned long long nb, char *base_to)
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

int	ft_puthexa_fd(long long int nbr, char *hexa_maj_or_min, int fd, int ct)
{
	long long int	nb;

	nb = nbr;
	if (nbr < 0)
	{
		nbr *= -1;
		ct += ft_putchar_fd('-', fd, ct);
	}
	if (nbr >= 16)
	{
		ft_puthexa_fd(nbr / 16, hexa_maj_or_min, fd, ct);
		ft_puthexa_fd(nbr % 16, hexa_maj_or_min, fd, ct);
	}
	else if (nbr < 16)
		ct += ft_putchar_fd(hexa_maj_or_min[nbr], fd, 0);
	return (ft_nbr_char_ct(nb, "0123456789abcdef"));
}

int	ft_puthexa_unsigned(unsigned long long nbr, char *hexa, int fd, int ct)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 16)
	{
		ft_puthexa_unsigned(nbr / 16, hexa, fd, ct);
		ft_puthexa_unsigned(nbr % 16, hexa, fd, ct);
	}
	else if (nbr < 16)
		ct += ft_putchar_fd(hexa[nbr], fd, 0);
	return (ft_nbr_char_ct(nbr, "0123456789abcdef"));
}

int	ft_putnbr_unsigned_fd(long long int nb, int fd, int ct)
{
	unsigned int	nbr;

	nbr = nb;
	if (nbr > 9)
	{
		ft_putnbr_unsigned_fd(nbr / 10, fd, ct);
		ft_putnbr_unsigned_fd(nbr % 10, fd, ct);
	}
	if (nbr <= 9)
		ct += ft_putchar_fd(nbr + 48, fd, ct);
	return (ft_nbr_char_ct(nbr, "0123456789"));
}

int	ft_putadrs_fd(unsigned long long pointer, int fd, int ct)
{
	write(1, "0x", 2);
	ft_puthexa_unsigned(pointer, "0123456789abcdef", fd, ct);
	return (ft_nbr_char_unsigned(pointer, "0123456789abcdef") + 2);
}
