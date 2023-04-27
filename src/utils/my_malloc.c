/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** my_malloc
*/

/* SYSTEM INCLUDES */
#include <stdlib.h>

/* LOCAL INCLUDES */
#include "player.h"
#include "map.h"
#include "menu.h"

void malloc_struct(menu_t *menu, map_t *map, player_t *player)
{
    menu->sprite_paralax = malloc(sizeof(sfSprite *));
    menu->texture_paralax = malloc(sizeof(sfTexture *));
    map->sprite_map = malloc(sizeof(sfSprite *));
    map->texture_map = malloc(sizeof(sfTexture *));
    map->sprite_epi = malloc(sizeof(sfSprite *));
    map->texture_epi = malloc(sizeof(sfTexture *));
    player->texture_idle = malloc(sizeof(sfTexture *));
    player->texture_walk = malloc(sizeof(sfTexture *));
    player->texture_attack = malloc(sizeof(sfTexture *));
    menu->button->sprite_button = malloc(sizeof(sfSprite *));
    menu->button->texture_button = malloc(sizeof(sfTexture *));
}
