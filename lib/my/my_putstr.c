/*
** EPITECH PROJECT, 2022
** my_putsr
** File description:
** jsp
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i;
    i = 0;
    while (str[i] != 0){
        my_putchar(str[i]);
        i = i + 1;
    }
}
