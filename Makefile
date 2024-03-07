NAME = push_swap
CHECKER = checker
SRCDIR = mandatory/
BSRCDIR = bonus/
CFILES = parsing.c utils.c init_stack.c nodes.c nodes2.c moves.c \
		parsing2.c moves2.c sortthree.c sort.c setcost.c rotations.c \
		settargets.c sortfive.c
BFILES = main.c getinput.c execinput.c
SRCS = $(addprefix $(SRCDIR), $(CFILES)) mandatory/main.c
BSRCS = $(addprefix $(BSRCDIR), $(BFILES)) $(addprefix $(SRCDIR), $(CFILES))
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

bonus: $(LIBFT) $(OBJS) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBFT) -o $(CHECKER)

clean:
	make clean -C libft
	rm -f $(BOBJS)
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(CHECKER)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus