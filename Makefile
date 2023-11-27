NAME		=	push_swap

LIB			=	libft.a

MAIN		=	main.c

SRC			=	push_swap.c		\
				utils.c			\
				main.c

OBJ			=	$(SRC:.c=.o)

RM			=	rm -f

FLG			=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJ)
			cc $(FLG) $(OBJ) -o $(NAME)

.PHONY	:	all bonus clean fclean re

%.o		:	%.c
			cc $(FLG) -c $< -o $@

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean 
			make