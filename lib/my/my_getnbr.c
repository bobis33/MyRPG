/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** mon getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i++;
    }
    return (nb * neg);
}
