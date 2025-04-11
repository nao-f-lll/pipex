CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

NAME    = pipex
SRCS    = pipex.c pipex_utils.c pipex_helpers.c pipex_io.c pipex_exec.c
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
