/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_set_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:19:54 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 15:17:15 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_texture_set_up(t_prg *prg)
{
	int	w;
	int	h;

	prg->grd.i_ref = mlx_xpm_file_to_image(prg->mlx, R, &w, &h);
	prg->rds.i_ref = mlx_xpm_file_to_image(prg->mlx, ERS, &w, &h);
	prg->cnw.i_ref = mlx_xpm_file_to_image(prg->mlx, CNW, &w, &h);
	prg->cne.i_ref = mlx_xpm_file_to_image(prg->mlx, CNE, &w, &h);
	prg->cse.i_ref = mlx_xpm_file_to_image(prg->mlx, CSE, &w, &h);
	prg->csw.i_ref = mlx_xpm_file_to_image(prg->mlx, CSW, &w, &h);
	prg->rdn.i_ref = mlx_xpm_file_to_image(prg->mlx, ERN, &w, &h);
	prg->wal.i_ref = mlx_xpm_file_to_image(prg->mlx, W, &w, &h);
	prg->wlw.i_ref = mlx_xpm_file_to_image(prg->mlx, WLW, &w, &h);
	prg->wle.i_ref = mlx_xpm_file_to_image(prg->mlx, WLE, &w, &h);
	prg->col.i_ref = mlx_xpm_file_to_image(prg->mlx, C, &w, &h);
	prg->ext.i_ref = mlx_xpm_file_to_image(prg->mlx, E, &w, &h);
	prg->per.fac = mlx_xpm_file_to_image(prg->mlx, PF, &w, &h);
	prg->per.fal = mlx_xpm_file_to_image(prg->mlx, PFL, &w, &h);
	prg->per.far = mlx_xpm_file_to_image(prg->mlx, PFR, &w, &h);
	prg->per.bck = mlx_xpm_file_to_image(prg->mlx, PB, &w, &h);
	prg->per.bks = mlx_xpm_file_to_image(prg->mlx, PBS, &w, &h);
	prg->per.lft = mlx_xpm_file_to_image(prg->mlx, PL, &w, &h);
	prg->per.lfi = mlx_xpm_file_to_image(prg->mlx, PIL, &w, &h);
	prg->per.rgt = mlx_xpm_file_to_image(prg->mlx, PR, &w, &h);
	prg->per.rgi = mlx_xpm_file_to_image(prg->mlx, PIR, &w, &h);
}

void	ft_anim_set_up(t_prg *prg)
{
	int	w;
	int	h;

	prg->cga.i_ref = mlx_xpm_file_to_image(prg->mlx, ACGT, &w, &h);
	prg->cga2.i_ref = mlx_xpm_file_to_image(prg->mlx, A2CGT, &w, &h);
	prg->exta.i_ref = mlx_xpm_file_to_image(prg->mlx, EA, &w, &h);
	prg->coa.i_ref = mlx_xpm_file_to_image(prg->mlx, CA1, &w, &h);
	prg->coa2.i_ref = mlx_xpm_file_to_image(prg->mlx, CA2, &w, &h);
	prg->blk1.i_ref = mlx_xpm_file_to_image(prg->mlx, BB1, &w, &h);
	prg->blkr.i_ref = mlx_xpm_file_to_image(prg->mlx, BBR, &w, &h);
	prg->blk2.i_ref = mlx_xpm_file_to_image(prg->mlx, BB2, &w, &h);
	prg->blk3.i_ref = mlx_xpm_file_to_image(prg->mlx, BB3, &w, &h);
	prg->los.i_ref = mlx_xpm_file_to_image(prg->mlx, L, &w, &h);
	prg->brr.i_ref = mlx_xpm_file_to_image(prg->mlx, BR3, &w, &h);
	prg->brl.i_ref = mlx_xpm_file_to_image(prg->mlx, BR2, &w, &h);
}
