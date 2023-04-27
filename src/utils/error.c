/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-elliot.masina
** File description:
** error
*/

/* SYSTEM INCLUDES */
#include <stddef.h>

/* LOCAL INCLUDES */
#include "constants.h"
#include "utils.h"
#include "my.h"

int check_env(const char *env[])
{
    if (!env)
        return (ERROR);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            return (SUCCESS);
    }

    return (ERROR);
}
