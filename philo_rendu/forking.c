/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:46:37 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/22 14:48:26 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	ft_last_philo(t_prg *prg, t_phi *phi)
{
	if ((pthread_mutex_lock(&phi->cutlery) == 0)
		& (pthread_mutex_lock(&prg->phi[0].cutlery) == 0))
	{
		if ((phi->r_fork == false && phi->l_fork == true)
			&& (prg->phi[0].r_fork == false && prg->phi[0].l_fork == true))
		{
			prg->phi[0].l_fork = false;
			phi->r_fork = true;
			ft_print(phi, FORKING);
			return (true);
		}
		return (false);
	}
	return (error);
}

static t_bool	ft_others(t_prg *prg, t_phi *phi)
{
	if ((pthread_mutex_lock(&phi->cutlery) == 0)
		& (pthread_mutex_lock(&prg->phi[phi->id].cutlery) == 0))
	{
		if ((phi->r_fork == false && phi->l_fork == true)
			&& (prg->phi[phi->id].r_fork == false)
			&& (prg->phi[phi->id].l_fork == true))
		{
			prg->phi[phi->id].l_fork = false;
			phi->r_fork = true;
			ft_print(phi, FORKING);
			return (true);
		}
		return (false);
	}
	return (error);
}

t_bool	ft_take_fork(t_prg *prg, t_phi *phi)
{
	if (prg->phi_nbr == 1)
		return (false);
	else if (phi->id == prg->phi_nbr)
		return (ft_last_philo(prg, phi));
	else
		return (ft_others(prg, phi));
}

t_bool	ft_release_fork(t_prg *prg, t_phi *phi)
{
	if (phi->id == prg->phi_nbr)
	{
		if (prg->phi[0].l_fork == false && prg->phi[0].r_fork == false)
		{
			prg->phi[0].l_fork = true;
			pthread_mutex_unlock(&prg->phi[0].cutlery);
			phi->r_fork = false;
			pthread_mutex_unlock(&phi->cutlery);
			return (true);
		}
	}
	else
	{
		if (prg->phi[phi->id].l_fork == false
			&& prg->phi[phi->id].r_fork == false)
		{
			prg->phi[phi->id].l_fork = true;
			pthread_mutex_unlock(&prg->phi[phi->id].cutlery);
			phi->r_fork = false;
			pthread_mutex_unlock(&phi->cutlery);
			return (true);
		}
	}
	return (false);
}
