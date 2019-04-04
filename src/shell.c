/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** shell.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "env.h"

int builtin(char *str)
{
    char **arr = my_str_to_word_array(str);

    if (my_strcomp(arr[0], "echo") && my_strcomp(arr[1], "$?")) {
        my_printf("%d\n", return_value);
        return_value = 0;
        return (1);
    }
    if (my_strcomp(arr[0], "cd")) {
        cd(arr);
        return_value = 0;
        return (1);
    }
    if (my_strcomp(arr[0], "exit")) {
        my_printf("exit\n");
        if (arr[1])
            exit(my_atoi(arr[1]));
        exit(0);
    }
    if (builtin_env(arr))
        return (1);
    return (0);
}

void manage_command(void)
{
    char *str;
    char **arr;
    int stat;

    display_prompt();
    str = gnl(0);
    if (!str)
        exit(0);
    stat = builtin(str);
    if (stat)
        return;
    arr = my_str_to_word_array(str);
    if (arr[0])
        search_path(arr);
    free(str);
}

void shell(void)
{
    char *buff = malloc(64);

    getcwd(buff, 64);
    while (1)
        manage_command();
}
