/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:48:10 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/10 16:04:26 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx_opengl_20191021/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define T "BELZEGUIN"
# define R "./xpm/road.xpm"
# define ERS "./xpm/end_road_south.xpm"
# define ERN "./xpm/end_road_north.xpm"
# define CNW "./xpm/corner_NW.xpm"
# define CNE "./xpm/corner_NE.xpm"
# define CSE "./xpm/corner_SE.xpm"
# define CSW "./xpm/corner_SW.xpm"
# define WLW "./xpm/west_wall.xpm"
# define WLE "./xpm/east_wall.xpm"
# define W "./xpm/CGT.xpm"
# define C "./xpm/baby.xpm"
# define CA1 "./xpm/baby_mid_bull.xpm"
# define CA2 "./xpm/baby_bull.xpm"
# define E "./xpm/exit.xpm"
# define EA "./xpm/exit_anim.xpm"
# define PF "./xpm/ping_idle_face.xpm" 
# define PFL "./xpm/ping_face_left_up.xpm" 
# define PFR "./xpm/ping_face_right_up.xpm" 
# define PB "./xpm/ping_back.xpm"
# define PBS "./xpm/ping_back_sec.xpm"
# define PL "./xpm/ping_left_side.xpm" 
# define PIL "./xpm/ping_idle_left.xpm" 
# define PR "./xpm/ping_right_side.xpm" 
# define PIR "./xpm/ping_idle_right.xpm" 
# define ACGT "./xpm/CGT_shaking_merguez.xpm"
# define A2CGT "./xpm/CGT_mid_shaking.xpm"
# define BB1 "./xpm/black_bloc.xpm"
# define BBR "./xpm/black_bloc_reversed.xpm"
# define BB2 "./xpm/black_bloc_shake_left.xpm"
# define BB3 "./xpm/black_bloc_shake_right.xpm"
# define BR2 "./xpm/black_bloc_shake_left_reversed.xpm"
# define BR3 "./xpm/black_bloc_shake_right_reversed.xpm"
# define L "./xpm/loose.xpm"

typedef struct s_coo
{
	int			x;
	int			y;
}				t_coo;

typedef struct s_win
{
	void		*win;
	int			wid;
	int			hgt;
}				t_win;

typedef struct s_char
{
	t_coo		coo;
	void		*fac;
	void		*far;
	void		*fal;
	void		*lft;
	void		*lfi;
	void		*rgt;
	void		*rgi;
	void		*bck;
	void		*bks;
}				t_char;

typedef struct s_img
{
	t_coo		coo;
	void		*i_ref;
}				t_img;

typedef struct s_prg
{
	char		**map;
	void		*mlx;
	t_win		win;
	t_img		grd;
	t_img		rds;
	t_img		rdn;
	t_img		cnw;
	t_img		cne;
	t_img		cse;
	t_img		csw;
	t_img		wal;
	t_img		wlw;
	t_img		wle;
	t_img		col;
	t_img		coa;
	t_img		coa2;
	t_img		ext;
	t_img		exta;
	t_img		cga;
	t_img		cga2;
	t_img		blkr;
	t_img		brr;
	t_img		brl;
	t_img		blk1;
	t_img		blk2;
	t_img		blk3;
	t_char		per;
	t_img		los;
	int			anim;
	int			anim_e;
	int			anim_a;
	int			anim_en_an;
	int			anim_baby;
	int			anim_stat;
	int			anim_stat_e;
	int			anim_stat_a;
	int			anim_stat_baby;
	int			en_stat;
	int			col_nb;
	int			lock;
	int			game_over;
}				t_prg;

int			line_ct(char **av);
int			ft_map_shape(char **map);
int			ft_check_map_input(char **map);
int			ft_map_size(char *map_line);
char		**ft_map_maker(char **av);
char		*ft_itoa(int nb);
void		ft_wait(void);
void		ft_walls_checker(char **map, int map_width, int map_height);
void		ft_check_amount(char **map, t_prg *prg);
void		ft_mv_up(t_prg *prg, int x, int y, int *steps);
void		ft_mv_dwn(t_prg *prg, int x, int y, int *steps);
void		ft_mv_rgt(t_prg *prg, int x, int y, int *steps);
void		ft_mv_lft(t_prg *prg, int x, int y, int *steps);
void		ft_pce(t_coo *coo, t_prg *prg, char c);
void		ft_wall_set_up(char **map, t_prg *prg, int i, int j);
void		ft_corner_set_up(char **map, t_prg *prg, int i, int j);
void		ft_middle_set_up(char **map, t_prg *prg, int i, int j);
void		ft_move_ennemy(t_prg *prg);
void		ft_anim_merguez(t_prg *prg);
void		ft_anim_exit(t_prg *prg);
void		ft_anim_col(t_prg *prg);
void		ft_anim_ennemy(t_prg *prg);
void		ft_texture_set_up(t_prg *prg);
void		ft_anim_set_up(t_prg *prg);
void		ft_init(int *b, int *c);
void		ft_init_four(int *a, int *b, int *c, int *d);
void		ft_scotch(int *i, int *coo);
void		ft_check_arg(int ac, char **av);

#endif
