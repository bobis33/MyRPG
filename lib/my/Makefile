##
## EPITECH PROJECT, 2022
## makefile
## File description:
## EPITECH Project Makefile for Lib
##

SRC			=		cat_str_int.c 						\
					is_digit.c							\
					my_compute_power_rec.c				\
					my_get_nbr_len.c					\
					my_getnbr.c							\
					my_isneg.c							\
					my_memcpy.c							\
					my_put_nbr.c						\
					my_putchar.c						\
					my_putstr.c							\
					my_realloc.c						\
					my_revstr.c							\
					my_strcat.c							\
					my_strcmp.c							\
					my_strcpy.c							\
					my_strlen.c							\
					my_strncmp.c						\

OBJ			=		$(SRC:.c=.o)

NAME		=		libmy.a

$(NAME):			$(OBJ)
					ar rc $(NAME) $(OBJ)
					cp $(NAME) ../

all:				$(NAME)

clean:
					rm -rf $(OBJ)

fclean:
					make clean
					rm -rf libmy.a

re:
					fclean all

.PHONY: 			all clean fclean re
