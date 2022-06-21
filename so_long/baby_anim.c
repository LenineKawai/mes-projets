/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:10:59 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 15:16:35 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_baby(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->col.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

static void	ft_baby_mid(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->coa.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

static void	ft_baby_full(char **map, t_prg *prg, int i, int j)
{
	t_coo	coo;

	ft_init(&coo.x, &coo.y);
	while (map[i])
	{
		j = 0;
		coo.x = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->coa2.i_ref,
					coo.x, coo.y);
			ft_scotch(&j, &coo.x);
		}
		ft_scotch(&i, &coo.y);
	}
}

void	ft_anim_col(t_prg *prg)
{
	if (prg->anim_baby == 3000)
	{
		if (prg->anim_stat_baby == 0)
		{
			ft_baby(prg->map, prg, 0, 0);
			prg->anim_stat_baby = 1;
		}
		else if (prg->anim_stat_baby == 1)
		{
			ft_baby_mid(prg->map, prg, 0, 0);
			prg->anim_stat_baby = 2;
		}
		else if (prg->anim_stat_baby == 2)
		{
			ft_baby_full(prg->map, prg, 0, 0);
			prg->anim_stat_baby = 0;
		}
			prg->anim_baby = 0;
	}
	prg->anim_baby ++;
}
