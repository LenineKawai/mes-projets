/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:44:08 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 15:06:37 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_merguez_up(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '1' && i != 0 && j != 0)
					&& (i != prg->win.hgt - 1 && j != ft_strlen(map[i]) - 2))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->wal.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

static void	ft_mid_merguez(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '1' && i != 0 && j != 0)
					&& (i != prg->win.hgt - 1 && j != ft_strlen(map[i]) - 2))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->cga2.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

static void	ft_merguez_down(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '1' && i != 0 && j != 0)
					&& (i != prg->win.hgt - 1 && j != ft_strlen(map[i]) - 2))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->cga.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

void	ft_anim_merguez(t_prg *prg)
{
	if (prg->anim == 3000)
	{
		if (prg->anim_stat == 0)
		{
			ft_merguez_up(prg->map, prg, 0, 0);
			prg->anim_stat = 1;
		}
		else if (prg->anim_stat == 1)
		{
			ft_merguez_down(prg->map, prg, 0, 0);
			prg->anim_stat = 2;
		}
		else if (prg->anim_stat == 2)
		{
			ft_mid_merguez(prg->map, prg, 0, 0);
			prg->anim_stat = 0;
		}
			prg->anim = 0;
	}
	prg->anim ++;
}
