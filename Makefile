SRC = 	ft_printf.c \
		process_i.c \
		process_u.c \
		process_s.c \
		process_xcapx.c \
		process_p.c \
		ft_tools.c \
		process_d.c

NAME = libftprintf.a

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

all : $(NAME)
	@true

$(NAME) :
	gcc -I $(FLAGS) -c $(FLAGS) $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(NAME)
	rm -rf $(OBJ)

fclean : clean

re : fclean all

.PHONY : all clean fclean re