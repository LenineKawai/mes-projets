SRCS = ft_atoi.c init.c main.c time.c thread.c forking.c deathening.c printing.c

OBJS = $(SRCS:.c=.o) 

INCL = philo.h

CC = gcc

FLAGS = -Wall -Werror -Wextra #-fsanitize=thread

RM = rm -f

%.o:%.c $(INCL) Makefile
	$(CC) $(FLAGS) -c $< -o $@

NAME = philo

$(NAME): $(OBJS) $(INCL) Makefile
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: make clean fclean all re
