NAME=libft.a
CC= cc
FLAGS= -Wall -Wextra -Werror
FUNC= ft_strlcat.c ft_strlen.c ft_substr.c ft_substr_exe.c\
       	ft_memcpy.c ft_split.c ft_split_exe.c ft_strdup.c\
	ft_strlcpy.c ft_strncmp.c ft_putchar.c ft_puthex.c\
       	ft_putptr.c ft_putunsnbr.c ft_printf.c ft_putnbr.c\
	ft_putstr.c\

OBJ=	 ft_strlcat.o ft_strlen.o ft_substr.o ft_substr_exe.o\
       	ft_memcpy.o ft_split.o ft_split_exe.o ft_strdup.o\
	ft_strlcpy.o ft_strncmp.o ft_putchar.o ft_puthex.o\
       	ft_putptr.o ft_putunsnbr.o ft_printf.o ft_putnbr.o\
	ft_putstr.o\

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(FUNC)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)
 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re
