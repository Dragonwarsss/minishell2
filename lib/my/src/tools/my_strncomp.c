/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strncomp
*/

int my_strncomp(char *s1, char *s2, int n)
{
    for (int i = 0; i != n; i += 1)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}
