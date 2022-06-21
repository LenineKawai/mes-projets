/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:53:11 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/25 10:14:48 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_phi *phi)
{
	ft_print(phi, EAT);
	pthread_mutex_lock(&phi->meal);
	phi->l_meal = ft_timems();
	pthread_mutex_unlock(&phi->meal);
	ft_usleep(phi->ptr->tt_eat, phi->ptr);
	if (phi->ptr->arg_nbr == 6)
		phi->meal_nb--;
}

static void	ft_sleep(t_phi *phi)
{
	ft_print(phi, SLEEP);
	ft_usleep(phi->ptr->tt_slp, phi->ptr);
	if (phi->id % 2 != 0)
		usleep(100);
}

static void	ft_normed_or_not_normed(t_phi *phi)
{
	ft_eat(phi);
	ft_release_fork(phi->ptr, phi);
	ft_sleep(phi);
	ft_print(phi, THINK);
	phi->ct = 0;
}

void	*ft_routine(void *ptr)
{
	t_phi	*phi;

	phi = (t_phi *)ptr;
	if (phi->id % 2 == 0)
	{
		printf("%lld %d is thinking\n", ft_timems() - phi->ptr->start, phi->id);
		usleep(100);
	}
	pthread_mutex_lock(&phi->ptr->death);
	while (phi->ptr->orbituary == false && phi->meal_nb > 0)
	{
		pthread_mutex_unlock(&phi->ptr->death);
		phi->checker = ft_take_fork(phi->ptr, phi);
		if (phi->checker == true)
			ft_normed_or_not_normed(phi);
		ft_release_fork(phi->ptr, phi);
	}
	pthread_mutex_unlock(&phi->ptr->death);
	return (NULL);
}

int	ft_thread(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->phi_nbr)
	{
		if (pthread_create(&prg->phi[i].thread, NULL,
				&ft_routine, &prg->phi[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&prg->reaper, NULL, &ft_deathening, prg) != 0)
		return (2);
	i = 0;
	while (i < prg->phi_nbr)
	{
		if (pthread_join(prg->phi[i].thread, NULL) != 0)
			return (3);
		i++;
	}
	if (pthread_join(prg->reaper, NULL) != 0)
		return (4);
	return (0);
}
