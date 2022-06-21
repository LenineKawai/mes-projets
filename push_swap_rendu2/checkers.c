/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:31:27 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/07 11:07:58 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	*ft_turn_into_int_array(char **av, int len, int nb_args)
{
	int	i;
	int	j;
	int	*array;

	array = malloc(len * sizeof(int));
	if (nb_args == 2)
		i = 0;
	if (nb_args != 2)
		i = 1;
	j = 0;
	while (av[i])
	{
		array[j] = ft_atoi(av[i]);
		i ++;
		j ++;
	}
	return (array);
}

int	ft_check_inputs_are_digits(char **av, int nb_args)
{
	int	i;
	int	j;

	if (nb_args == 2)
		i = 0;
	if (nb_args != 2)
		i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' && av[i][j + 1] != '\0')
				j ++;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
			j ++;
		}
		i++;
	}
	return (0);
}

int	ft_is_sorted(int *array, int len, int nb_args)
{
	int	i;

	i = 0;
	if (nb_args != 2)
		len -= 1;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (1);
		i ++;
	}
	return (0);
}

int	ft_check_for_dub(int *array, int len)
{
	int	i;
	int	j;
	int	*dup;	

	i = -1;
	j = 0;
	dup = malloc(len * sizeof(int));
	while (++i < len)
		dup[i] = array[i];
	i = -1;
	while (++i < len)
	{
		j = i + 1;
		while (j < len - 1)
		{
			if (array[i] == dup[j])
			{
				free(dup);
				return (1);
			}
			j ++;
		}
	}
	free(dup);
	return (0);
}
