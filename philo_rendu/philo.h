/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <mgolinva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:54:55 by mgolinva          #+#    #+#             */
/*   Updated: 2022/04/25 11:46:14 by mgolinva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# define EAT 1
# define SLEEP 2
# define THINK 3
# define FORKING 4

typedef enum e_bool
{
	false,
	true,
	error
}	t_bool;

typedef struct s_phi
{
	int				id;
	int				ct;
	int				meal_nb;
	long long int	l_meal;
	struct s_prg	*ptr;
	t_bool			r_fork;
	t_bool			l_fork;
	t_bool			checker;
	pthread_mutex_t	cutlery;
	pthread_mutex_t	meal;
	pthread_t		thread;
}					t_phi;

typedef struct s_prg
{
	int				phi_nbr;
	int				tt_die;
	int				tt_eat;
	int				tt_slp;
	int				meal_nbr;
	int				arg_nbr;
	long long int	start;
	t_bool			orbituary;
	t_phi			*phi;
	pthread_t		reaper;
	pthread_mutex_t	death;
}					t_prg;

int				ft_atoi(const char *str);

void			ft_init(int ac, char **av, t_prg *prg);

void			ft_print(t_phi *phi, int action);

long long int	ft_timems(void);
void			ft_usleep(long long int time, t_prg *prg);

int				ft_thread(t_prg *prg);

t_bool			ft_take_fork(t_prg *prg, t_phi *phi);
t_bool			ft_release_fork(t_prg *prg, t_phi *phi);

void			*ft_deathening(void *ptr);

#endif