/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:34:41 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/22 18:19:10 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long int time, t_prg *prg)
{
	long long int	i;

	(void)prg;
	i = ft_timems();
	usleep(time * 0.90);
	while (1)
	{
		if (((ft_timems() - i) * 1000) >= time)
			break ;
		usleep(50);
	}
}

long long int	ft_timems(void)
{
	struct timeval	start;
	long long int	time;

	gettimeofday(&start, NULL);
	time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (time);
}
