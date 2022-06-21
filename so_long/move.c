/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:47:14 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 15:12:04 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mv_up(t_prg *prg, int x, int y, int *steps)
{
	char	*s;

	prg->per.coo.y -= 64;
	if (prg->anim != 0 && prg->anim % 2 == 0)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.bks,
			prg->per.coo.x, prg->per.coo.y);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.bck,
			prg->per.coo.x, prg->per.coo.y);
	mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
		prg->per.coo.x, prg->per.coo.y + 64);
	if (prg->map[y][x] == 'E')
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->ext.i_ref,
			prg->per.coo.x, prg->per.coo.y + 64);
	if (prg->map[y][x] == 'C')
	{
		prg->col_nb --;
		prg->map[y][x] = '0';
	}
	*steps += 1;
	s = ft_itoa(*steps);
	mlx_string_put(prg->mlx, prg->win.win, prg->per.coo.x, prg->per.coo.y + 20,
		0, s);
	free(s);
}

void	ft_mv_lft(t_prg *prg, int x, int y, int *steps)
{
	char	*s;

	prg->per.coo.x -= 64;
	if (prg->anim != 0 && prg->anim % 2 == 0)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.lfi,
			prg->per.coo.x, prg->per.coo.y);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.lft,
			prg->per.coo.x, prg->per.coo.y);
	mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
		prg->per.coo.x + 64, prg->per.coo.y);
	if (prg->map[y][x] == 'E')
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->ext.i_ref,
			prg->per.coo.x + 64, prg->per.coo.y);
	if (prg->map[y][x] == 'C')
	{
		prg->col_nb --;
		prg->map[y][x] = '0';
	}
	*steps += 1;
	s = ft_itoa(*steps);
	mlx_string_put(prg->mlx, prg->win.win, prg->per.coo.x, prg->per.coo.y + 20,
		0, s);
	free(s);
}

void	ft_mv_dwn(t_prg *prg, int x, int y, int *steps)
{
	char	*s;

	prg->per.coo.y += 64;
	if (prg->anim != 0 && prg->anim % 2 == 0)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.far,
			prg->per.coo.x, prg->per.coo.y);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.fal,
			prg->per.coo.x, prg->per.coo.y);
	mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
		prg->per.coo.x, prg->per.coo.y - 64);
	if (prg->map[y][x] == 'E')
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->ext.i_ref,
			prg->per.coo.x, prg->per.coo.y - 64);
	if (prg->map[y][x] == 'C')
	{
		prg->col_nb --;
		prg->map[y][x] = '0';
	}
	*steps += 1;
	s = ft_itoa(*steps);
	mlx_string_put(prg->mlx, prg->win.win, prg->per.coo.x, prg->per.coo.y + 20,
		0, s);
	free(s);
}

void	ft_mv_rgt(t_prg *prg, int x, int y, int *steps)
{
	char	*s;

	prg->per.coo.x += 64;
	if (prg->anim != 0 && prg->anim % 2 == 0)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.rgi,
			prg->per.coo.x, prg->per.coo.y);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->per.rgt,
			prg->per.coo.x, prg->per.coo.y);
	mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
		prg->per.coo.x - 64, prg->per.coo.y);
	if (prg->map[y][x] == 'E')
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->ext.i_ref,
			prg->per.coo.x - 64, prg->per.coo.y);
	if (prg->map[y][x] == 'C')
	{
		prg->col_nb --;
		prg->map[y][x] = '0';
	}
	*steps += 1;
	s = ft_itoa(*steps);
	mlx_string_put(prg->mlx, prg->win.win, prg->per.coo.x, prg->per.coo.y + 20,
		0, s);
	free(s);
}
