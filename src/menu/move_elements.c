/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** move_elements
*/

#include "player.h"

void move_pnj(pnj_t **pnj)
{
    for (int i = 0; i < 8; i++) {
        sfSprite_move(pnj[i]->sprite_pnj, (sfVector2f){0, 3});
        sfSprite_move(pnj[i]->sprite_bubble, (sfVector2f){0, 3});
    }
}

void move_mobs(mobs_t **mobs)
{
    for (int i = 0; i < 10; i++) {
        sfSprite_move(mobs[i]->sprite, (sfVector2f){0, 3});
    }
}

int replace_map(map_t *map, player_t *player)
{
    sfSprite_move(map->sprite_map[0], (sfVector2f){0, 3});
    sfSprite_move(map->sprite_map[1], (sfVector2f){0, 3});
    sfSprite_move(map->sprite_map[2], (sfVector2f){0, 3});
    move_pnj(player->pnj);
    move_mobs(player->mobs);
    if (sfSprite_getPosition(map->sprite_map[0]).y > -7000)
        return 1;
    return 0;
}
