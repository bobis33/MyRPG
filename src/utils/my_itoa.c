/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** my_itoa
*/

#include <stdlib.h>

#include "my.h"

char *my_itoa(int nb)
{
    if (nb == 0)
        return ("0");
    int i = 0; int j = 0; int nb2 = nb;
    char *str = malloc(sizeof(char) * 100);
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb = nb * -1;
    }
    while (nb2 != 0) {
        nb2 = nb2 / 10;
        j++;
    }
    while (j != 0) {
        str[i] = (nb / my_compute_power_rec(10, j - 1)) + 48;
        nb = nb % my_compute_power_rec(10, j - 1);
        i++; j--;
    }
    str[i] = '\0';
    return (str);
}
