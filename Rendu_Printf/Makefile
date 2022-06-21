SRCS = ft_printf.c ft_utilities.c ft_putnbr_base_fd.c

INCL = ft_printf.h

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

RM = rm -f

%.o: %.c	$(INCL)
			$(CC) $(FLAGS) -g -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) libft.gch

fclean:	clean
			$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
