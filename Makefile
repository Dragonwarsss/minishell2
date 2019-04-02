##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -Iinclude

NAME	=	mysh

SRCS	=	src/main.c			\
		src/shell.c			\
		src/display_prompt.c		\
		src/cd.c			\
		src/set_paths.c			\
		src/exe_path.c			\
		src/search_path.c		\
		src/builtin_env.c		\
		src/display_env.c		\
		src/open_redirection.c		\
		src/replace_arg_var.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic -Llib/my -lmy

all:	libs $(NAME)

libs:
	$(MAKE) -C lib/my/ OUTDIR=.

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib/my/
	find . -path "./*" -name "*.gcno" -type f -delete -o -name "*.gcda" -delete

re: fclean all

tests_run:
	$(MAKE) -C unit_tests/
	cd unit_tests && ./test
	gcovr

.PHONY: all clean fclean re tests_run
