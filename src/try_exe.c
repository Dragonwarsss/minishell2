/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** try_exe
*/

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include "my.h"
#include "env.h"

static void is_coredumped(int stat)
{
    if (WCOREDUMP(stat))
        my_puterr(" (core dumped)");
    my_puterr("\n");
}

int try_exe(char *path, char **bin)
{
    pid_t pid = fork();
    int stat;

    if (pid == 0) {
        stat = execve(path, bin, envp);
        if (stat == -1) {
            my_puterr(bin[0]);
            my_puterr(": Permission denied.\n");
            exit(0);
            return (0);
        }
    } else {
        waitpid(pid, &stat, WUNTRACED);
        if (WIFSIGNALED(stat)) {
            print_exit_status((char*)strsignal(WTERMSIG(stat)));
            is_coredumped(stat);
        }
        return_value = stat;
    }
    return (1);
}
