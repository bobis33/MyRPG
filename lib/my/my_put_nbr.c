/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** mon put_nbr
*/
#include <unistd.h>

void my_put_nbr(int nb)
{
    long nbr = 0; long nbr2 = 0; long nbr3 = 0;
    nbr = nb;
    if (nbr < 0) {
        write(1, "-", 1);
        nbr = nbr * -1;
    } if (nbr > 9) {
        my_put_nbr(nbr / 10);
        nbr2 = 48 + nbr % 10;
        write(1, &nbr2, 1);
    } else {
        nbr3 = 48 + nbr;
        write(1, &nbr3, 1);
    }
}
