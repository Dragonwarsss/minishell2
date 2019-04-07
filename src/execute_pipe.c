/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** execute pipe
*/

#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "env.h"

int do_pipe(char ***args)
{
    int pipefd[2];
    int pid;
    int stat;
    int stat2;

    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        dup2(pipefd[0], 0);
        close(pipefd[1]);
        stat = execve(search_exe_path(args[1][0]), args[1], envp);
        if (stat == -1)
            exit(84);
    } else {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        stat2 = execve(search_exe_path(args[0][0]), args[0], envp);
        waitpid(-1, &stat, 0);
        if (stat2 == -1)
            exit(84);
        return (pid);
    }
    return (0);
}

int execute_pipe(char ***args)
{
    int pid = fork();
    int stat;
    int pid2;
    int wpid;

    if (pid == 0)
        pid2 = do_pipe(args);
    else {
        for (int i = 0; i != 10000000; i += 1);
        return (0);
    }

    return (0);
}
