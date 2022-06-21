# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:25:57 by mgolinva          #+#    #+#              #
#    Updated: 2022/03/10 10:37:06 by mgolinva         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = Vanilla/cmd_parser.c Vanilla/ft_split.c Vanilla/utils.c Vanilla/chained_list.c Vanilla/pipex.c Vanilla/command_list_maker.c Vanilla/printing_ft.c Vanilla/path_list_creator.c Vanilla/main.c Vanilla/la_norm_stp_stop.c

BNS = Bonus/cmd_parser_bonus.c Bonus/ft_split_bonus.c Bonus/utils_bonus.c Bonus/chained_list_bonus.c Bonus/main_bonus.c Bonus/pipex_bonus.c Bonus/command_list_maker_bonus.c Bonus/printing_ft_bonus.c Bonus/path_list_creator_bonus.c Bonus/la_norm_stp_stop_bonus.c

OBJS = $(SRCS:.c=.o)

BNSOBJS = $(BNS:.c=.o)

INCL = ./BONUS/pipex.h

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

RM = rm -f

%.o: %.c $(INCL) Makefile
	$(CC) $(FLAGS) -c $< -o $@

NAME =	pipex

NAMEBNS = pipex_bonus

all: $(NAME)

$(NAME): $(OBJS) $(INCL) Makefile
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

bonus: $(NAMEBNS)

$(NAMEBNS): $(BNSOBJS) $(INCL) Makefile
	$(CC) $(FLAGS) -o $(NAMEBNS) $(BNSOBJS)

clean:
	$(RM) $(OBJS) $(BNSOBJS)

fclean: clean
	$(RM) $(NAME) $(NAMEBNS)

re: clean all

rebon: clean bonus

.PHONY: make clean fclean re all bonus
