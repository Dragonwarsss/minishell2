/*
** EPITECH PROJECT, 2018
** my_strcomp
** File description:
** my_strcomp
*/

int my_strlen(char *str);

int my_strcomp(char *s1, char *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    for (; s1[i]; i += 1)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}
