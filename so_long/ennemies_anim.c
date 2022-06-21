/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:08:00 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/08 16:04:19 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_ennemy_set(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map [i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (map[i][j] == 'A')
			{
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
					co.x, co.y);
				if (prg->en_stat == 0)
					mlx_put_image_to_window(prg->mlx, prg->win.win,
						prg->blk1.i_ref, co.x, co.y);
				else
					mlx_put_image_to_window(prg->mlx, prg->win.win,
						prg->blkr.i_ref, co.x, co.y);
			}	
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}	
}

static void	ft_ennemy_left(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map [i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (map[i][j] == 'A')
			{
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
					co.x, co.y);
				if (prg->en_stat == 0)
					mlx_put_image_to_window(prg->mlx, prg->win.win,
						prg->blk2.i_ref, co.x, co.y);
				else
					mlx_put_image_to_window(prg->mlx, prg->win.win,
						prg->brl.i_ref, co.x, co.y);
			}	
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}	
}

static void	ft_ennemy_right(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map [i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (map[i][j] == 'A')
			{
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
					co.x, co.y);
				if (prg->en_stat == 0)
					mlx_put_image_to_window(prg->mlx, prg->win.win,
						prg->blk1.i_ref, co.x, co.y);
				else
					mlx_put_image_to_window(prg->mlx, prg->win.win,
						prg->brr.i_ref, co.x, co.y);
			}	
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}	
}

void	ft_anim_ennemy(t_prg *prg)
{
	if (prg->anim_en_an == 1000)
	{
		if (prg->anim_stat_a == 0)
		{
			ft_ennemy_set(prg->map, prg, 0, 0);
			prg->anim_stat_a = 1;
		}
		else if (prg->anim_stat_a == 1)
		{
			ft_ennemy_left(prg->map, prg, 0, 0);
			prg->anim_stat_a = 2;
		}
		else if (prg->anim_stat_a == 2)
		{
			ft_ennemy_right(prg->map, prg, 0, 0);
			prg->anim_stat_a = 0;
		}
		prg->anim_en_an = 0;
	}
	prg->anim_en_an ++;
}
