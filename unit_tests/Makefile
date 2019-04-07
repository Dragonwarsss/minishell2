##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -I../include

NAME	=	test

SRCS	=	test.c				\
		../src/copy.c			\
		../src/shell.c			\
		../src/display_prompt.c		\
		../src/cd.c			\
		../src/set_paths.c			\
		../src/exe_path.c			\
		../src/search_path.c		\
		../src/builtin_env.c		\
		../src/display_env.c		\
		../src/open_redirection.c		\
		../src/replace_arg_var.c		\
		../src/exit_status.c		\
		../src/try_exe.c			\
		../src/trypath.c			\
		../src/cd_check_wrong.c		\
		../src/check_pipe_or_semi.c	\
		../src/keep_correct_args.c		\
		../src/keep_correct_sep.c		\
		../src/is_sep.c			\
		../src/only_semi.c			\
		../src/only_pipe.c			\
		../src/execute_semi.c		\
		../src/search_exe_path.c		\
		../src/execute_pipe.c		\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic -L../lib/my -lmy -lcriterion --coverage

all:	libs $(NAME)

libs:
	$(MAKE) -C ../lib/my/ OUTDIR=.

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) NAME
re: fclean all

.PHONY: all clean fclean re tests_run
