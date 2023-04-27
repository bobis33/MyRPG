/*
** EPITECH PROJECT, 2023
** lib*
** File description:
** my_strcat
*/

int my_strlen(char const * str);

char *my_strcat(char *dest, char const *src)
{
    int destl = my_strlen(dest);
    int i;

    for (i = 0 ; src[i] != '\0' ; i++) {
        dest[destl + i] = src[i];
    }

    dest[destl + i] = '\0';

    return (dest);
}
