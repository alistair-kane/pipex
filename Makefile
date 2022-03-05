NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
SRCS	= src/ft_calloc.c src/ft_split.c src/ft_strjoin.c src/ft_strncmp.c src/ft_memmove.c src/ft_strlen.c pipex.c
BONUS	= src/ft_calloc.c src/ft_split.c src/ft_strjoin.c src/ft_strncmp.c src/ft_memmove.c src/ft_strlen.c pipex.c
 

OBJS	= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 
	rm -f $(OBJS)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS)
	rm -f $(BONUS_OBJS)

clean:
	rm -f $(OBJS) 
# $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) checker

re:	fclean all

.PHONY: all bonus clean fclean re