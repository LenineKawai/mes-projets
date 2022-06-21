/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:44:41 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/22 17:23:16 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_phi *phi, int action)
{
	pthread_mutex_lock(&phi->ptr->death);
	if (phi->ptr->orbituary == false)
	{
		pthread_mutex_unlock(&phi->ptr->death);
		if (action == EAT)
			printf("%lld %d is eating\n",
				ft_timems() - phi->ptr->start, phi->id);
		if (action == SLEEP)
			printf("%lld %d is sleeping\n",
				ft_timems() - phi->ptr->start, phi->id);
		if (action == THINK)
			printf("%lld %d is thinking\n",
				ft_timems() - phi->ptr->start, phi->id);
		if (action == FORKING)
		{
			printf("%lld %d has taken a fork\n",
				ft_timems() - phi->ptr->start, phi->id);
			printf("%lld %d has taken a fork\n",
				ft_timems() - phi->ptr->start, phi->id);
		}
	}
	pthread_mutex_unlock(&phi->ptr->death);
}
