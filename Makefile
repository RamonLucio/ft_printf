SRC		=	ft_printf.c

OBJ		=	$(SRC:.c=.o)
NAME	=	libftprintf.a
CC		=	gcc
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
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
