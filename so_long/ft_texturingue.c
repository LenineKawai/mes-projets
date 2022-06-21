/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturingue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:05:06 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 15:19:59 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pce(t_coo *coo, t_prg *prg, char c)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
			coo->x, coo->y);
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.rgt,
			coo->x, coo->y);
		prg->per.coo.x = coo->x;
		prg->per.coo.y = coo->y;
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
			coo->x, coo->y);
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->col.i_ref,
			coo->x, coo->y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
			coo->x, coo->y);
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->ext.i_ref,
			coo->x, coo->y);
	}
}

void	ft_middle_set_up(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				ft_pce(&coo, prg, map[i][j]);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
					coo.x, coo.y);
			else if ((map[i][j] == '1' && i != 0 && j != 0)
				&& (i != prg->win.hgt - 1 && j != ft_strlen(map[i]) - 2))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->wal.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

void	ft_wall_set_up(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map[i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (j == 0)
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->wlw.i_ref,
					co.x, co.y);
			else if ((j == ft_strlen(map[i]) - 2)
				&& (i != 0 && i < prg->win.hgt - 1))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->wle.i_ref,
					co.x, co.y);
			else if (i != 0 && i == prg->win.hgt - 1 && map[i][j] == '1' )
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->rds.i_ref,
					co.x, co.y);
			else if (i == 0 && map[i][j] == '1' && map[i + 1])
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->rdn.i_ref,
					co.x, co.y);
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}
}

void	ft_corner_set_up(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map [i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (i == 0 && j == 0)
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->cnw.i_ref,
					co.x, co.y);
			else if (i == 0 && j == ft_strlen(map[i]) - 2)
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->cne.i_ref,
					co.x, co.y);
			else if (i == prg->win.hgt - 1 && j == prg->win.wid - 1)
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->cse.i_ref,
					co.x, co.y);
			else if ((i == prg->win.hgt - 1 && j == 0 && map[i - 1][j] == '1')
					&& (map[i][j + 1] == '1'))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->csw.i_ref,
					co.x, co.y);
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}
}
