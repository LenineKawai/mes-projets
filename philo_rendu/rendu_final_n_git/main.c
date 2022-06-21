/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:54:53 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/26 10:01:19 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	ft_only_digit(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				printf("we don't take kindly on non-digit in args around"
					" here stranger.\n");
				return (error);
			}
			j ++;
		}
		i ++;
	}
	return (true);
}

static t_bool	ft_check_args(char **av, int ac)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) != (int)ft_atoi(av[i]) || ft_atoi(av[i]) < 0)
		{
			printf("We don't take kindly on non-integers"
				" and negativ numbers around here, stranger.\n");
			return (error);
		}
		if (i > 1 && i != 5 && ft_atoi(av[i]) < 60)
		{
			printf("We don't take kindly on times under 60"
				" around here, stranger.\n");
			return (error);
		}
	}
	if (ft_atoi(av[1]) == 0)
	{
		printf("We don't take kindly on the absence of philosopher"
			" around here, stranger\n");
		return (error);
	}
	return (ft_only_digit(av, ac));
}

int	main(int ac, char **av)
{
	t_prg	prg;

	if (ac < 5 || ac > 6)
	{
		printf("We don't take kindly on more than 6 or less"
			" than 4 args around here, stranger\n");
		return (1);
	}
	if (ft_check_args(av, ac) == error)
		return (2);
	if (ac == 5)
	{
		ft_init(ac, av, &prg);
		ft_thread(&prg);
	}
	if (ac == 6)
	{
		ft_init(ac, av, &prg);
		ft_thread(&prg);
	}
	free(prg.phi);
	return (0);
}
