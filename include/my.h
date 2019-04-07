/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stddef.h>

#ifndef MY_H_
    #define MY_H_

typedef struct s_function function_t;

struct s_function {
    void (*ptr)(int);
    char c;
    function_t *next;
};

void my_printf(char *str, ...);
void my_put_nbr(int nb);
void my_put_nbr_binary(int nb);
void my_put_nbr_hexa(int nb);
void my_put_nbr_hexaup(int nb);
void my_put_nbr_octal(int nb);
void my_put_ptr(int nb);
void my_put_nbr_unsigned(int nb);
void my_putstr(char *str);
void my_putchar(int nb);

int my_atoi(char *s);
char *my_itoa(int n);

void free_ll(function_t *fnc);
function_t *push_ll(function_t *fnc, char c);
function_t *create_ll_3(function_t *fnc);
function_t *create_ll_2(function_t *fnc);
function_t *create_ll(void);

void my_puterr(char *str);

void *my_malloc(size_t size);
int my_strlen(char const *str);
int my_strcomp(char *s1, char *s2);
int my_strncomp(char *s1, char *s2, int n);
char *my_strcpy(char *s1, char const *s2);
char *my_strdup(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strconcat(char *s1, char *s2);
char *my_strcpynjump(char *str, int n);
char **my_str_to_word_array(char *str);

char *gnl(int fd);

char **sort_tab(char **tab, int size);
char **manage_tab(char **tab, int size);
char **move_words(char **tab, int i);
int is_sorted(char **tab, int size);
int compare_words(char *str1, char *str2);
char *my_putlow(char *str);

int compare_words_reverse(char *str1, char *str2);
int is_sorted_reverse(char **tab, int size);
int is_sorted_reverse(char **tab, int size);
char **manage_tab_reverse(char **tab, int size);
char **sort_tab_reverse(char **tab, int size);

#endif
