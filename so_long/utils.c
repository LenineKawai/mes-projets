/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:56:58 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 16:03:52 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(int *b, int *c)
{
	*b = 0;
	*c = 0;
}

void	ft_init_four(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

void	ft_scotch(int *i, int *coo)
{
	*i += 1;
	*coo += 64;
}

void	ft_wait(void)
{
	int	i;

	i = 0;
	while (i < 1000000000)
		i ++;
}

int	line_ct(char **av)
{
	int		fd;
	int		ct;
	char	nl[2];

	ct = 0;
	fd = open(av[1], O_RDONLY);
	while (read(fd, nl, 1) != 0)
	{
		if (nl[0] == 0)
			exit (0);
		if (ft_strchr(nl, '\n') != NULL)
			ct ++;
	}
	close (fd);
	return (ct);
}
