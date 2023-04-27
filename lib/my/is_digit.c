/*
** EPITECH PROJECT, 2022
** is digit
** File description:
** is digit
*/

int is_digit(char *str)
{
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    for (; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
            return (0);
    }
    return (1);
}
