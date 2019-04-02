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


typedef enum {
    LS_COLOR,
    MODULES_RUN_QUARANTINE,
    LANG,
    GDM_LANG,
    HISTCONTROL,
    DISPLAY,
    HOSTNAME,
    COLORTERM,
    IMSETTINGS_INTEFRATE_DESKTOP,
    KDEDIRS,
    XGD_VTNR,
    SSH_AUTH_SOCK,
    XDG_SESSION_ID,
    XDG_GREETER_DATA_DIR,
    MODULES_CMD,
    USER,
    ENV,
    DESKTOP_SESSION,
    IMSETTINGS_MODULE,
    PWD,
    SSH_ASKPASS,
    HOME,
    SSH_AGENT,
    XDG_SESSION_TYPE,
    BASH_ENV,
    XDG_DATA_DIRS,
    XDG_SESSION_DESKTOP,
    LOADEDMODULES,
    MAIL,
    TERM,
    SHELL,
    VTE_VERSION,
    XDG_SEAT_PATH,
    QT_IM_MODULE,
    XMODIFIERS,
    XDG_CURRENT_DESKTOP,
    MOZ_GMP_PATH,
    XDG_SEAT,
    SHLVL,
    WINDOWID,
    MODULEPATH,
    GDMSESSION,
    LOGNAME,
    DBUS_SESSION_BUS_ADDRESS,
    XDG_RUNTIME,
    XAUTHORITY,
    MODULE_PATH_modshare,
    XDG_SESSION_PATH,
    PATH,
} env;

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
void cd(char *arg);
void set_paths(char **env);
void search_path(char **arr);
int exe_path(char *path, char **bin);
void copy_home(char **env);
char *file_redirect(char **bin);
int open_redirection(int redirection, char *file);
void replace_arg_var(char **arr);
void display_env(void);
int builtin_env(char **arr);

#endif
