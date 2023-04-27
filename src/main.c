/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.sourbets
** File description:
** main
*/


#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>

#include "constants.h"
#include "utils.h"
#include "player.h"
#include "game.h"


int create_window(void)
{
    window_t *window = malloc(sizeof(window_t));
    menu_t *menu = malloc(sizeof(menu_t));
    map_t *map = malloc(sizeof(map_t));
    player_t *player = malloc(sizeof(player_t));
    menu->button = malloc(sizeof(button_t));

    if (window == NULL || menu == NULL
    || map == NULL || player == NULL || menu->button == NULL)
        return ERROR;

    malloc_struct(menu, map, player);
    player_array(player);

    game_init(window, menu, map, player);
    game_loop(window, menu, map, player);
    if (window->is_left == 1) {
        sfRenderWindow_destroy(window->window);
        free(window);
    }
    return SUCCESS;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[],
const char *env[])
{
    if (check_env(env) == ERROR
    || create_window() == ERROR)
        return EPITECH_ERROR;
    return SUCCESS;
}
