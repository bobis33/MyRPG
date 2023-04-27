/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.sourbets
** File description:
** my_memcpy
*/
#include <stddef.h>

void my_memcpy(char *dest, char *src, size_t size)
{
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}
