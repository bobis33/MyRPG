/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-jules.sourbets
** File description:
** my_realloc
*/
#include <stdlib.h>

void my_memcpy(char *dest, char *src, size_t size);

void *my_realloc(void *ptr, size_t size)
{
    void *ptr2 = malloc(size);
    if (ptr2 == NULL)
        return NULL;
    if (ptr != NULL) {
        my_memcpy(ptr2, ptr, size);
        free(ptr);
    }
    return ptr2;
}
