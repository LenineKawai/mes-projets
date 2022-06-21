SRCS = push_swap.c chained.c checkers.c stack_handling.c rotate.c free_ft.c simplify.c radix.c sorting.c sort_utils.c

INCL = libft/libft.h push_swap.h

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c $(INCL)
		$(CC) $(FLAGS) -c $< -o $@

NAME = push_swap

all: lib $(NAME)

lib :
	@$(MAKE) -C ./libft/

$(NAME): $(OBJS) $(INCL) $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRCS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean: 
	$(RM) $(OBJS) push_swap.h.gch
	@$(MAKE) clean -C ./libft/

fclean: clean
		$(RM) $(NAME)
		@$(MAKE) fclean -C ./libft/

re: clean all

.PHONY: make clean fclean re all
