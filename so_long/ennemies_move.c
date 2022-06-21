/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:25:21 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/08 17:29:01 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_right(t_prg *prg, int i, int *j)
{
	while (prg->map[i][*j] && prg->en_stat == 0)
	{
		if (prg->map[i][*j] == 'A' && prg->map[i][*j + 1] == '0')
		{
			mlx_put_image_to_window(prg->mlx, prg->win.win, prg->blk1.i_ref,
				(*j + 1) * 64, i * 64);
			mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
				*j * 64, i * 64);
			prg->map[i][*j] = '0';
			prg->map[i][*j + 1] = 'A';
			if (prg->map[i][*j + 2] != '0')
				prg->en_stat = 1;
			break ;
		}
		*j += 1;
	}
}

static void	ft_move_left(t_prg *prg, int i, int *j)
{
	while (prg->map[i][*j] && prg->en_stat == 1)
	{
		if (prg->map[i][*j] == 'A' && prg->map[i][*j - 1] == '0')
		{
			mlx_put_image_to_window(prg->mlx, prg->win.win, prg->blkr.i_ref,
				(*j - 1) * 64, i * 64);
			mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
				*j * 64, i * 64);
			prg->map[i][*j] = '0';
			prg->map[i][*j - 1] = 'A';
			if (prg->map[i][*j - 2] != '0')
				prg->en_stat = 0;
			break ;
		}
		*j += 1;
	}
}

void	ft_move_ennemy(t_prg *prg)
{
	static int	i;
	static int	j;

	if (i >= prg->win.hgt - 1 || j < 0)
		i = 0;
	if (prg->anim_a == 4000)
	{
		while (prg->map[i])
		{
			if (j >= prg->win.wid - 3 || j < 0)
				j = 0;
			if (prg->en_stat == 0)
				ft_move_right(prg, i, &j);
			else if (prg->en_stat == 1)
				ft_move_left(prg, i, &j);
			i ++;
		}
		prg->anim_a = 0;
	}
	prg->anim_a ++;
}
