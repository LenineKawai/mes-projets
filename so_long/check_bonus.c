/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:50:01 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/08 15:57:27 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error_m(int cte, int ctp, t_prg *prg)
{
	if (ctp == 0)
	{
		printf("there are no character on this map.\n");
		exit (0);
	}
	if (ctp > 1)
	{
		printf("This ain't a coop game, only one char plz.\n");
		exit (0);
	}
	if (cte == 0)
	{
		printf("We cannot get out. add an exit you fool !\n");
		exit (0);
	}
	if (cte > 1)
	{
		printf("too many exit kills the exits. \n");
		exit (0);
	}
	if (prg->col_nb == 0)
	{
		printf("no collectible, no game\n");
		exit (0);
	}
}

int	ft_map_shape(char **map)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = ft_map_size(map[0]);
	while (map[i])
	{
		if (line_size != ft_map_size(map[i]))
		{
			printf("Error, map is not a square, unlike Sponge Bob.\n");
			exit (0);
		}
		i ++;
	}
	return (line_size);
}

int	ft_check_map_input(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C')
				&& (map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				&& (map[i][j] != 'A'))
			{
				printf("Error, there is an intruder in the map file !\n");
				exit (0);
			}
			j ++;
		}
		i ++;
	}
	return (i);
}

void	ft_check_amount(char **map, t_prg *prg)
{
	int	i;
	int	j;
	int	cte;
	int	ctp;

	i = 0;
	cte = 0;
	ctp = 0;
	prg->col_nb = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				cte ++;
			else if (map[i][j] == 'P')
				ctp ++;
			else if (map[i][j] == 'C')
				prg->col_nb ++;
			j ++;
		}
		i ++;
	}
	ft_error_m(cte, ctp, prg);
}

void	ft_walls_checker(char **map, int map_width, int map_height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != '1' && map[i][j] != '\n')
					&& (i == 0 || i == map_height - 1))
			{
				printf("weak walls, fill the gaps.\n");
				exit (0);
			}
			j ++;
		}
		if (map[i][0] != '1' || map[i][map_width - 2] != '1')
		{
			printf("weak walls, fill the gaps.\n");
			exit (0);
		}
		i ++;
	}
}
