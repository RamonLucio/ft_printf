SRC		=	ft_printf.c ft_printf_utils.c

OBJ		=	$(SRC:.c=.o)
NAME	=	libftprintf.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJ)
			ar rcs ${NAME} ${OBJ}

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
