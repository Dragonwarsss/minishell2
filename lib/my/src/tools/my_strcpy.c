/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcpy
*/

char *my_strcpy(char *s1, char const *s2)
{
    int i;

    for (i = 0; s2[i]; i += 1)
        s1[i] = s2[i];
    s1[i] = '\0';
    return (s1);
}
