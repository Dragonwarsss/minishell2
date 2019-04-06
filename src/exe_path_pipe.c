/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** exe_path
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include "my.h"
#include "env.h"

int exe_path_pipe(char ***cmd)
{
    pid_t pid = fork();
    char *info_path = malloc(PATH_MAX);
    int stat;
    int p[2];
    int fd_in = 0;

    while (*cmd != NULL) {
        pipe(p);
        if (pid == 0) {
            dup2(fd_in, 0);
            if (*(cmd + 1) != NULL)
                dup2(p[1], 1);
            close(p[0]);
            info_path = search_exe_path(*cmd[0]);
            stat = execve(info_path, *cmd, envp);
        } else {
            waitpid(pid, &stat, WUNTRACED);
            if (WIFSIGNALED(stat)) {
                print_exit_status(stat);
#ifdef WCOREDUMP
                if (WCOREDUMP(stat) == 128)
                    my_puterr(" (core dumped)\n");
                else
                    my_puterr("\n");
#endif
            }
            return_value = stat;
            close(p[1]);
            fd_in = p[0];
            cmd++;
        }
    }
    return (1);
}
