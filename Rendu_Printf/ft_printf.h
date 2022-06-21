/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:29:11 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/23 09:48:21 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(const char *str);
int		ft_nbr_char_ct(long long int nb, char *base_to);
int		ft_putnbr_unsigned_fd(long long int nbr, int fd, int ct);
int		ft_putnbr_fd(int nb, int fd, int ct);
int		ft_putchar_fd(char c, int fd, int ct);
int		ft_putstr_fd(char *str, int fd, int ct);
int		ft_puthexa_fd(long long int nbr, char *hexa_maj_or_min, int fd, int ct);
int		ft_puthexa_unsigned(unsigned long long nbr, char *hexa, int fd, int ct);
int		ft_putadrs_fd(unsigned long long pointer, int fd, int ct);
int		ft_printf(const char *str, ...);

#endif
