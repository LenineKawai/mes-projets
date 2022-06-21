/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:28:54 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/23 10:41:07 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_spec_char(char str)
{
	if ((str == 'c' || str == 's' || str == 'p' || str == 'd' || str == 'i')
		|| (str == 'u' || str == 'x' || str == 'X' || str == '%'))
		return (1);
	else
		return (0);
}

static int	ft_va_arg_handling(char *str, va_list ap, int i)
{
	int	ct;

	ct = 0;
	if (str[i + 1] == 'c')
		ct += ft_putchar_fd(va_arg(ap, int), 1, 0);
	else if (str[i + 1] == 's')
		ct += ft_putstr_fd(va_arg(ap, char *), 1, 0);
	else if (str[i + 1] == 'p')
		ct += ft_putadrs_fd(va_arg(ap, unsigned long long), 1, 0);
	else if (str[i + 1] == 'd')
		ct += ft_putnbr_fd(va_arg(ap, int), 1, 0);
	else if (str[i + 1] == 'i')
		ct += ft_putnbr_fd(va_arg(ap, int), 1, 0);
	else if (str[i + 1] == 'u')
		ct += ft_putnbr_unsigned_fd(va_arg(ap, unsigned int), 1, 0);
	else if (str[i + 1] == 'x')
		ct += ft_puthexa_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1, 0);
	else if (str[i + 1] == 'X')
		ct += ft_puthexa_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1, 0);
	else if (str[i + 1] == '%')
		ct += ft_putchar_fd('%', 1, 0);
	return (ct);
}

static int	ft_actual_printing(char *str, va_list ap, int i)
{
	int	return_value;

	return_value = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i], 1, 0);
			return_value ++;
			i++;
		}
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (ft_is_spec_char(str[i + 1]) == 0 && str[i + 1] != '\0')
				i ++;
			else
			{
			return_value += ft_va_arg_handling(str, ap, i);
			i += 2;
			}
		}
	}
	return (return_value);
}

int	ft_printf(const char *str, ...)
{
	int		return_value;

	va_list (ap);
	va_start(ap, str);
	return_value = ft_actual_printing((char *)str, ap, 0);
	va_end(ap);
	return (return_value);
}
