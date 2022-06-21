# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 09:58:31 by mgolinva          #+#    #+#              #
#    Updated: 2022/02/10 16:39:37 by mgolinva         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = ft_itoa.c ennemies_anim.c ennemies_move.c baby_anim.c exit_anim.c img_set_up.c ft_texturingue.c move.c utils.c wall_anim.c ft_map_checker.c ft_map_maker.c so_long.c get_next_line.c get_next_line_utils.c

BONUS = ft_itoa.c ennemies_anim.c ennemies_move.c baby_anim.c exit_anim.c img_set_up.c ft_texturingue.c move.c utils.c wall_anim.c check_bonus.c ft_map_maker.c so_long.c get_next_line.c get_next_line_utils.c

INCL = so_long.h get_next_line.h minilibx_opengl_20191021/mlx.h

MLXA = minilibx_opengl_20191021/libmlx.a

OBJS = $(SRCS:.c=.o)

BOBJS = $(BONUS:.c=.o)

CC = gcc 

FLAGS = -Wall -Wextra -Werror 

MLXCC = -Imlx -framework OpenGL -framework AppKit

RM = rm -f

%.o: %.c $(INCL) Makefile
	$(CC) -c $< -o $@

NAME = so_long

all: mlx $(NAME)

mlx: 
	@$(MAKE) -C ./minilibx_opengl_20191021/

$(NAME): $(OBJS) $(INCL) Makefile
	@$(CC) $(FLAGS) -c $(SRCS)
	@$(CC) $(FLAGS) $(MLXCC) -o $(NAME) $(OBJS) $(MLXA)
	$(RM) check_bonus.o

clean:
	$(RM) check_bonus.o
	$(RM) $(OBJS)
	$(MAKE) clean -C ./minilibx_opengl_20191021/

fclean: clean
	$(MAKE) clean -C ./minilibx_opengl_20191021/
	$(RM) $(NAME)

bonus: $(BOBJS) $(INCL) mlx Makefile
	$(RM) $(OBJS)
	@$(CC) $(FLAGS) -c $(BONUS)
	@$(CC) $(FLAGS) $(MLXCC) -o $(NAME) $(BOBJS) $(MLXA)


re : clean all

.PHONY: make clean fclean re bonus mlx all
