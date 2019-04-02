##
## EPITECH PROJECT, 2017
## PSU_my_printf
## File description:
## A makefile for my_printf
##

CC	=	gcc -I.

NAME	=	libmy.a

SRCS	=	src/printf.c				\
		src/linked_list.c			\
		src/my_put_nbr.c			\
		src/nbr/my_put_nbr_binary.c		\
		src/nbr/my_put_nbr_hexa.c		\
		src/nbr/my_put_nbr_hexaup.c		\
		src/nbr/my_put_nbr_octal.c		\
		src/nbr/my_put_nbr_unsigned.c		\
		src/nbr/my_put_ptr.c			\
		src/tools/my_strlen.c			\
		src/tools/my_puterr.c			\
		src/tools/my_strcomp.c			\
		src/tools/strtol.c			\
		src/tools/ltostr.c			\
		src/tools/gnl.c				\
		src/tools/my_str_to_word_array.c	\
		src/sort/sort_tab.c			\
		src/sort/is_sorted.c			\
		src/sort/sort_tab_reverse.c		\
		src/sort/is_sorted_reverse.c		\
		src/tools/my_strcpy.c			\
		src/tools/my_malloc.c			\
		src/tools/my_strncomp.c			\
		src/tools/my_strcat.c			\
		src/tools/my_strdup.c			\
		src/tools/my_strconcat.c		\
		src/tools/my_strcpynjump.c		\

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	mkdir -p ../../include/
	cp my.h ../../include/
	cp is.h ../../include/

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
