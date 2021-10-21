SRC		=	ft_printf.c ft_printf_utils.c

OBJ		=	$(SRC:.c=.o)
NAME	=	libftprintf.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	./libft/libft.a

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJ)
			cd libft && make
			cp $(LIBFT) $(NAME)
			ar rcs ${NAME} ${OBJ}

all:		$(NAME)

clean:
			cd libft && make fclean
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
