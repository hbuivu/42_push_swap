NAME = push_swap
BNAME = checker

SRCS = utils.c utils2.c ft_split.c error_management.c \
		parse_entries.c parse_error.c \
		rotate.c push.c swap.c \
		simple_sort.c \
		presort.c dlist.c find_index.c find_best_move.c push_move.c complex_sort.c \
		main.c
BSRCS = utils.c utils2.c ft_split.c error_management.c \
		parse_entries.c parse_error.c \
		bonus_rotate.c bonus_push.c bonus_swap.c \
		bonus_checker.c 

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

all: $(NAME)

bonus: $(BNAME)
		
clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BNAME)

re: fclean all

.PHONY: all clean fclean re