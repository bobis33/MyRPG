/*
** EPITECH PROJECT, 2023
** my_get_nbr_len
** File description:
** my_get_nbr_len
*/

int my_get_nbr_len(int nb)
{
    int i = 0;

    if (nb < 0) {
        nb = nb * -1;
        i++;
    }

    while (nb > 0) {
        nb = nb / 10;
        i++;
    }

    return (i);
}
