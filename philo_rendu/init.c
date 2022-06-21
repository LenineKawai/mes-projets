/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:03:32 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/25 10:14:49 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_phi(t_prg *prg)
{
	int	i;

	i = 0;
	prg->phi = malloc(prg->phi_nbr * sizeof(t_phi));
	while (i < prg->phi_nbr)
	{
		prg->phi[i].id = i + 1;
		prg->phi[i].ct = 0;
		prg->phi[i].l_meal = prg->start;
		prg->phi[i].meal_nb = prg->meal_nbr;
		prg->phi[i].r_fork = false;
		prg->phi[i].l_fork = true;
		prg->phi[i].ptr = prg;
		pthread_mutex_init(&prg->phi[i].cutlery, NULL);
		pthread_mutex_init(&prg->phi[i].meal, NULL);
		i++;
	}
}

static void	ft_args(int ac, char **av, t_prg *prg)
{
	prg->phi_nbr = ft_atoi(av[1]);
	prg->tt_die = ft_atoi(av[2]) * 1000;
	prg->tt_eat = ft_atoi(av[3]) * 1000;
	prg->tt_slp = ft_atoi(av[4]) * 1000;
	prg->meal_nbr = 1;
	if (ac == 6)
	{
		prg->meal_nbr = ft_atoi(av[5]);
		prg->arg_nbr = ac;
	}
}

void	ft_init(int ac, char **av, t_prg *prg)
{
	prg->start = ft_timems();
	prg->orbituary = false;
	ft_args(ac, av, prg);
	ft_phi(prg);
	pthread_mutex_init(&prg->death, NULL);
}
