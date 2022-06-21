/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:55:50 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 15:16:48 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_low_flame(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'E')
				&& (prg->per.coo.x != j * 64 && prg->per.coo.y != i * 64))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->ext.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

static void	ft_high_flame(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'E')
				&& (prg->per.coo.x != j * 64 && prg->per.coo.y != i * 64))
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->exta.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

void	ft_anim_exit(t_prg *prg)
{
	if (prg->anim_e == 3000)
	{
		if (prg->anim_stat_e == 0)
		{
			ft_low_flame(prg->map, prg, 0, 0);
			prg->anim_stat_e = 1;
		}
		else if (prg->anim_stat_e == 1)
		{
			ft_high_flame(prg->map, prg, 0, 0);
			prg->anim_stat_e = 0;
		}
		prg->anim_e = 0;
	}
	prg->anim_e ++;
}
