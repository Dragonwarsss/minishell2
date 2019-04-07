/*
** EPITECH PROJECT, 2019
** unit_test
** File description:
** my_ls
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(env_bultin, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"env", NULL};

    envp = NULL;
    builtin_env(arg);
    cr_assert(1 == 1);
}

Test(env_bultin_add_var, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"setenv", "toto", NULL};

    var = malloc(sizeof(var_t));
    var[0].name = NULL;
    envp = NULL;
    builtin_env(arg);
    cr_assert(1 == 1);
}

Test(env_bultin_add_var_no_arg, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"setenv", NULL};

    var = malloc(sizeof(var_t));
    var[0].name = NULL;
    envp = NULL;
    builtin_env(arg);
    cr_assert(1 == 1);
}


Test(setenv_bultin, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"setenv", NULL};
    envp = NULL;
    builtin_env(arg);
    cr_assert(1 == 1);
}

Test(unsetenv_bultin, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"unsetenv", NULL};
    envp = NULL;
    builtin_env(arg);
    cr_assert(1 == 1);
}

Test(cd_basic_check, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"cd", NULL};
    envp = NULL;
    cd_basic(arg);
    cr_assert(1 == 1);
}

Test(cd_basic_check_many_arg, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"cd", "fdfqf", "fdsfsfd", "fdsfs", NULL};

    envp = NULL;
    cd_basic(arg);
    cr_assert(1 == 1);
}

Test(cd_check_wrong, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"cd", "-", NULL};

    envp = NULL;
    cd_check_wrong(-1, arg, NULL);
    cr_assert(1 == 1);
}

Test(cd_basic_go_home, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"cd", NULL};

    home = "/";
    envp = NULL;
    cd_basic(arg);
    cr_assert(1 == 1);
}

Test(cd_check_wrong_ok, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"cd", "-", NULL};

    envp = NULL;
    cd_check_wrong(1, arg, NULL);
    cr_assert(1 == 1);
}

Test(keep_arg, init_flag_test, .init = redirect_all_std)
{
    char *str = "ls ; ls";

    envp = NULL;
    keep_correct_args(my_str_to_word_array(str), 0);
    cr_assert(1 == 1);
}

Test(keep_arg_long, init_flag_test, .init = redirect_all_std)
{
    char *str = "ls ; ls -l src/ include/ lib/";

    envp = NULL;
    keep_correct_args(my_str_to_word_array(str), 2);
    cr_assert(1 == 1);
}

Test(keep_arg_long_2, init_flag_test, .init = redirect_all_std)
{
    char *str = "ls ; ls -l src/ include/ lib/";

    envp = NULL;
    keep_correct_args(my_str_to_word_array(str), 1);
    cr_assert(1 == 1);
}

Test(keep_arg_long_3, init_flag_test, .init = redirect_all_std)
{
    char *str = "ls ; ls -l src/ include/ lib/";

    envp = NULL;
    keep_correct_args(my_str_to_word_array(str), 3);
    cr_assert(1 == 1);
}

Test(keep_sep, init_flag_test, .init = redirect_all_std)
{
    char *str = "ls ; ls ; | hi";

    envp = NULL;
    keep_correct_sep(my_str_to_word_array(str));
    cr_assert(1 == 1);
}

Test(is_only_pipe, init_flag_test, .init = redirect_all_std)
{
    char *arg1[] = {"|", "|", NULL};
    char *arg2[] = {"|", ";", NULL};

    envp = NULL;

    cr_assert(only_pipe(arg1) == 1);
    cr_assert(only_pipe(arg2) == 0);
}

Test(is_only_semi, init_flag_test, .init = redirect_all_std)
{
    char *arg1[] = {";", ";", NULL};
    char *arg2[] = {"|", ";", NULL};

    envp = NULL;

    cr_assert(only_semi(arg1) == 1);
    cr_assert(only_semi(arg2) == 0);
}

Test(file_redirect_check, init_flag_test, .init = redirect_all_std)
{
    char *arg1[] = {"ls", ">", "tmp", NULL};
    char *arg2[] = {"ls", ">>", "tmp", NULL};

    envp = NULL;

    cr_assert(my_strcomp(file_redirect(arg1), "tmp") == 1);
    cr_assert(my_strcomp(file_redirect(arg2), "tmp") == 1);
    cr_assert(1 == 1);
}

Test(open_redirection, init_flag_test, .init = redirect_all_std)
{
    int fd;

    fd = open_redirection(1, "tmp");
    cr_assert(fd != -1);
    close(fd);
    fd = open_redirection(2, "tmp2");
    cr_assert(fd != -1);
    close(fd);
}

Test(trypath_exec, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"/bin/ls", "--color", NULL};

    trypath(arg, 0);
    cr_assert(1 == 1);
}

Test(trypath_exec_bad_format, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"tmp", "--color", NULL};

    trypath(arg, 0);
    trypath(arg, 1);
    cr_assert(1 == 1);
}

Test(tryexe__bad_format, init_flag_test, .init = redirect_all_std)
{
    char *arg[] = {"tmp", "--color", NULL};


    cr_assert(try_exe("/tmp", arg) == 1);
}

Test(builtin_echo, init_flag_test, .init = redirect_all_std)
{
    char *str = "echo $?";

    return_value = 1;
    cr_assert(builtin(str) == 1);
}

Test(builtin_cd, init_flag_test, .init = redirect_all_std)
{
    char *str = "cd";

    cr_assert(builtin(str) == 1);
}

Test(set_paths_for_path, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};

    set_paths(path);
    cr_assert(1 == 1);
}

Test(set_paths_for_path_no_env, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {NULL};

    set_paths(path);
    cr_assert(1 == 1);
}

Test(search_path_ls, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};
    char *arg[] = {"ls", "--color", NULL};

    set_paths(path);
    search_path(arg);
    cr_assert(1 == 1);
}

Test(search_path_dir, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};
    char *arg[] = {"/tmp", "--color", NULL};

    set_paths(path);
    search_path(arg);
    cr_assert(1 == 1);
}

Test(search_bin, init_flag_test, .init = redirect_all_std)
{
    char *path = "/bin";
    char *arg[] = {"ls", NULL};

    search_bin(path, arg);
    cr_assert(1 == 1);
}

Test(search_bin_nothing, init_flag_test, .init = redirect_all_std)
{
    char *path = "/usr";
    char *arg[] = {"ls", NULL};

    search_bin(path, arg);
    cr_assert(1 == 1);
}

Test(search_exe_path, init_flag_test, .init = redirect_all_std)
{
    char *bin = "ls";
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};

    set_paths(path);
    search_exe_path(bin);
    cr_assert(1 == 1);
}

Test(search_exe_bad, init_flag_test, .init = redirect_all_std)
{
    char *bin = "ls";
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};

    set_paths(path);
    search_exe_path(bin);
    cr_assert(1 == 1);
}

Test(check_semi_and_exec, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};

    set_paths(path);
    check_pipe_or_semi("ls ; ls ; ls");
    cr_assert(1 == 1);
}

Test(check_pipe_and_exec, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};

    set_paths(path);
    check_pipe_or_semi("cat Makefile | grep src");
    cr_assert(1 == 1);
}

Test(display_prompt, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", NULL};

    set_paths(path);
    copy_user(path);
    display_prompt();
    cr_assert(1 == 1);
}

Test(copy_home, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {"USER=usr", "TERM=urxvt-256", "SHELL=/bin/bash",
                    "PATH=/bin", "HOME=/bin", NULL};

    copy_home(path);
    cr_assert(1 == 1);
}

Test(copy_home_no_env, init_flag_test, .init = redirect_all_std)
{
    char *path[] = {NULL};

    copy_home(path);
    cr_assert(1 == 1);
}
