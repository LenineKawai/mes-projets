/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:53:22 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 16:48:43 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(char **map, t_prg *prog)
{
	int		map_width;
	int		map_height;

	map_width = ft_map_shape(map);
	map_height = ft_check_map_input(map);
	ft_check_amount(map, prog);
	ft_walls_checker(map, map_width, map_height);
	prog->win.wid = map_width - 1;
	prog->win.hgt = map_height;
}

int	ft_cross_exit(t_prg *prg)
{
	(void) prg;
	exit (0);
}

int	ft_move(int keycode, t_prg *prg)
{	
	int				x;
	int				y;
	static int		steps = 0;

	x = prg->per.coo.x / 64;
	y = prg->per.coo.y / 64;
	if (prg->lock == 0 && prg->map[y][x] == 'E')
		exit (0);
	if (keycode == 53)
		exit(0);
	if (keycode == 13 && prg->map[y - 1][x] != '1')
		ft_mv_up(prg, x, y, &steps);
	if (keycode == 0 && prg->map[y][x - 1] != '1')
		ft_mv_lft(prg, x, y, &steps);
	if (keycode == 1 && prg->map[y + 1][x] != '1')
		ft_mv_dwn(prg, x, y, &steps);
	if (keycode == 2 && prg->map[y][x + 1] != '1')
		ft_mv_rgt(prg, x, y, &steps);
	if (prg->col_nb == 0)
		prg->lock = 0;
	printf("steps = %d\n", steps);
	return (0);
}

int	ft_anim(t_prg *prg)
{
	int	x;
	int	y;

	if (prg->game_over == 1)
	{
		ft_wait();
		exit(0);
	}
	x = prg->per.coo.x / 64;
	y = prg->per.coo.y / 64;
	ft_anim_merguez(prg);
	ft_anim_exit(prg);
	ft_anim_col(prg);
	ft_move_ennemy(prg);
	ft_anim_ennemy(prg);
	if (prg->map[y][x] == 'A')
	{
		mlx_clear_window(prg->mlx, prg->win.win);
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->los.i_ref,
			(prg->win.wid) * 64 / 2 - 240, (prg->win.hgt) * 64 / 2 - 240);
		prg->game_over = 1;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_prg	prg;

	ft_check_arg(ac, av);
	ft_init(&i, &j);
	ft_init_four(&prg.anim_a, &prg.game_over, &prg.en_stat, &prg.anim_baby);
	ft_init_four(&prg.anim, &prg.anim_e, &prg.anim_stat, &prg.anim_stat_e);
	prg.lock = 1;
	prg.map = ft_map_maker(av);
	ft_map_error(prg.map, &prg);
	prg.mlx = mlx_init();
	prg.win.win = mlx_new_window(prg.mlx, prg.win.wid * 64,
			prg.win.hgt * 64, T);
	ft_texture_set_up(&prg);
	ft_anim_set_up(&prg);
	ft_middle_set_up(prg.map, &prg, i, j);
	ft_wall_set_up(prg.map, &prg, i, j);
	ft_corner_set_up(prg.map, &prg, i, j);
	mlx_loop_hook(prg.mlx, ft_anim, &prg);
	mlx_hook(prg.win.win, 2, 0, ft_move, &prg);
	mlx_hook(prg.win.win, 17, 0, ft_cross_exit, &prg);
	mlx_loop(prg.mlx);
	exit (0);
}
