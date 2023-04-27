/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copie string into an other
*/

char *my_strcha(char *strrev, char const *str, int rev)
{
    int i = 0;
    while (str[i] != 0) {
        strrev[i] = str[rev];
        i = i + 1;
        rev = rev - 1;
    }
    return (strrev);
}

char *my_revstr(char *str)
{
    int rev = 0;
    int i = 0;
    while (str[i] != '\0') {
        rev = rev + 1;
        i = i + 1;
    }
    i = 0;
    rev = rev - 1;
    char strrev[rev];
    my_strcha(strrev, str, rev);
    str = strrev;
    return str;
}
