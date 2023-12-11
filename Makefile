NAME		=	push_swap

NAME_B		=	checker

LIB			=	libft.a

SRC_B		=	src/main.c				\
				src/swap.c				\
				src/push.c				\
				src/rotate.c			\
				src/rotate_reverse.c

SRC			=	src/push_swap.c			\
				src/sort_small_list.c	\
				src/utils.c				\
				src/utils_2.c			\
				src/swap.c				\
				src/push.c				\
				src/rotate.c			\
				src/rotate_reverse.c	\
				src/printlst.c			\
				src/input_errors.c		\
				src/main.c

OBJ			=	$(SRC:.c=.o)

OBJ_B		=	$(SRC_B:.c=.o)

RM			=	rm -f

FLG			=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJ)
			make -C libft
			cp libft/libft.a $(LIB)
			cc $(FLG) $(OBJ) -o $(NAME) $(LIB)

.PHONY	:	all clean fclean re bonus

bonus	:	

%.o		:	%.c
			cc $(FLG) -c $< -o $@ -g3

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean 
			make