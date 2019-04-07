/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** env.h
*/

#ifndef ENV_H
#define ENV_H

typedef struct s_var var_t;

struct s_var {
    char *name;
    char *value;
};

char *curr_dir;
char **envp;
char **paths;
char *user;
char *home;
int return_value;
var_t *var;
char *last_path;

void shell(void);
void display_prompt(void);
void manage_command(void);
int builtin(char *str);
void cd(char **arg);
void set_paths(char **env);
void search_path(char **arr);
int exe_path(char *path, char **bin);
void copy_home(char **env);
char *file_redirect(char **bin);
int open_redirection(int redirection, char *file);
void replace_arg_var(char **arr);
void display_env(void);
int builtin_env(char **arr);
void print_exit_status(char *str);
char *concat_path(char *info_path, char *path, char *bin);
int only_pipe(char **sep);
char **keep_correct_args(char **args, int i);
char **keep_correct_sep(char **args);
int execute_pipe(char ***args);
int is_sep(char *str);
char *search_exe_path(char *bin);
void trypath(char **arr, int stat);
void print_error(char *path, int stat);
int try_exe(char *path, char **bin);
void cd_check_wrong(int stat, char **arg, char *tmp);
int check_pipe_or_semi(char *str);
char **keep_correct_sep(char **args);
int only_semi(char **sep);
void execute_semi(char ***args);
void random_func(int sig);
void copy_user(char **env);
void copy_env(char **env);

#endif
