/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** do_pipe.c
*/

int is_pipe(char **arg)
{
    int i = 0;

    for (; arg[i]; i += 1)
        if (my_strcomp(arg[i], "|"))
            return (1);
    return (0);
}
