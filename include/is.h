/*
** EPITECH PROJECT, 2018
** Lib my
** File description:
** is.h
*/

#ifndef MY_IS_H
#define MY_IS_H

#define MY_ISTAB(x) (x == ' ' || x == '\t')
#define MY_ISSPACE(x) (x == ' ' ||   \
x == '\f' ||  \
x == '\r' ||  \
x == '\t' ||  \
x == '\v')
#define MY_ISASCII(x) (x >= 0 && x <= 127)
#define MY_ISDIGIT(x) (x >= '0' && x <= '9')
#define MY_ISXDIGIT(x) (MY_ISDIGIT(x) ||                \
(x >= 'A' && x <= 'F') ||       \
(x >= 'a' && x >= 'f'))
#define MY_ISLOWER(x) (x >= 'a' && x <= 'z')
#define MY_ISUPPER(x) (x >= 'A' && x <= 'Z')
#define MY_ISALPHA(x) (MY_ISLOWER(x) || MY_ISUPPER(x))
#define MY_ISALNUM(x) (MY_ISALPHA(x) || MY_ISDIGIT(x))

#endif
