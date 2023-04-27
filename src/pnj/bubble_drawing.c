/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** bubble_drawing
*/

#include "player.h"

void draw_bubble_map1(player_t *player, window_t *window, int i)
{
    if (player->pnj[i]->is_bubble == 1)
        sfRenderWindow_drawSprite(window->window,
            player->pnj[i]->sprite_bubble, NULL);
}

void draw_bubble_map2(player_t *player, window_t *window, int i)
{
    if (player->pnj[i]->is_bubble == 1)
        sfRenderWindow_drawSprite(window->window,
            player->pnj[i]->sprite_bubble, NULL);
}
