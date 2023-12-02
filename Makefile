NAME		=	push_swap

LIB			=	libft.a

MAIN		=	main.c

SRC			=	src/push_swap.c		\
				src/utils.c			\
				src/swap.c			\
				src/main.c

OBJ			=	$(SRC:.c=.o)

RM			=	rm -f

FLG			=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJ)
			make -C libft
			cp libft/libft.a $(LIB)
			cc $(FLG) $(OBJ) -o $(NAME) $(LIB)

.PHONY	:	all bonus clean fclean re

%.o		:	%.c
			cc $(FLG) -c $< -o $@ -g3

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean 
			make