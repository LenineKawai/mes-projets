/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathening.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:21:45 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/25 11:33:16 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_orbituary_set(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->phi_nbr)
	{
		pthread_mutex_lock(&prg->death);
		prg->orbituary = true;
		pthread_mutex_unlock(&prg->death);
		i++;
	}
}

static void	ft_i_suck(t_prg *prg, int i)
{
	if (ft_timems() >= prg->start
		+ (prg->meal_nbr * prg->tt_eat / 1000)
		+ (prg->meal_nbr * prg->tt_slp / 1000))
		return ;
	else
		printf("%lld : philo #%d is dead\n",
			(ft_timems() - prg->start), prg->phi[i].id);
}

static void	ft_six(t_prg *prg)
{
	int	i;

	while (ft_timems() <= prg->start + (prg->meal_nbr * prg->tt_eat / 1000)
		+ (prg->meal_nbr * prg->tt_slp / 1000))
	{
		i = 0;
		while (i < prg->phi_nbr)
		{
			pthread_mutex_lock(&prg->phi[i].meal);
			if ((ft_timems() >= prg->phi[i].l_meal + prg->tt_die / 1000))
			{
				pthread_mutex_unlock(&prg->phi[i].meal);
				ft_orbituary_set(prg);
				ft_i_suck(prg, i);
				return ;
			}
			pthread_mutex_unlock(&prg->phi[i].meal);
			i++;
		}
	}
}

static void	ft_five(t_prg *prg)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < prg->phi_nbr)
		{
			pthread_mutex_lock(&prg->phi[i].meal);
			if ((ft_timems() >= prg->phi[i].l_meal + prg->tt_die / 1000))
			{
				pthread_mutex_unlock(&prg->phi[i].meal);
				ft_orbituary_set(prg);
				printf("%lld %d is dead (RIP)\n",
					(ft_timems() - prg->start), prg->phi[i].id);
				return ;
			}
			pthread_mutex_unlock(&prg->phi[i].meal);
		}
	}
	return ;
}

void	*ft_deathening(void *ptr)
{
	t_prg	*prg;

	prg = ptr;
	if (prg->arg_nbr == 6)
	{
		ft_six(prg);
	}
	else
		ft_five(prg);
	return (NULL);
}
