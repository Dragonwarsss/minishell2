/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_to_word_array
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char *src, int n)
{
    int	i;

    i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

int is_alnum(char c)
{
    if (c == ':')
        return (0);
    if (c <= ' ' || c >= 127)
        return (0);
    return (1);
}

int word_count(char *str)
{
    int i = 0;
    int word = 0;

    while (str != NULL && str[i]) {
        if (is_alnum(str[i]) && !is_alnum(str[i + 1]))
            word = word + 1;
        i = i + 1;
    }
    return (word);
}

char **my_str_to_word_array(char *str)
{
    int	j = 0;
    int	i = 0;
    char **wordtab;
    int	len = 0;

    wordtab = malloc((word_count(str) + 1) * sizeof(char *));
    while (str != NULL && str[i]) {
        if (is_alnum(str[i]))
            len = len + 1;
        if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0) {
            wordtab[j] = malloc(len + 1);
            my_strncpy(wordtab[j], &str[i - len + 1], len);
            len = 0;
            j = j + 1;
	}
        i = i + 1;
    }
    wordtab[j] = NULL;
    return (wordtab);
}
