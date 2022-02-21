NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
SRCS	= 
# BONUS	= 

OBJS	= ${SRCS:.c=.o}
# BONUS_OBJS	= ${BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 
	rm -f $(OBJS)

# bonus: $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) -o checker $(BONUS_OBJS) -L $(LIB_LOC) -lft
# 	rm -f $(BONUS_OBJS)

clean:
	rm -f $(OBJS) 
# $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) checker

re:	fclean all

.PHONY: all bonus clean fclean re