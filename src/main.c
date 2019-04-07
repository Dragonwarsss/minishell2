/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main.c
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"

int main(__attribute__((unused))int argc,
__attribute__((unused))char **argv, char **env)
{
    signal(SIGINT, random_func);
    last_path = malloc(4096);
    var = malloc(sizeof(var_t));
    var[0].name = NULL;
    return_value = 0;
    copy_env(env);
    copy_home(env);
    set_paths(env);
    copy_user(env);
    shell();
    return (return_value);
}
