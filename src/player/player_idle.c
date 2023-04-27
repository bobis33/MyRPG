/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** player_idle
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "player.h"

void player_idle(int *walk, int *rect_index, player_t *player)
{
    if (*walk == 1) {
        *rect_index = 0; *walk = 0;
        sfSprite_setTexture(player->sprite_player,
        player->texture_idle[3], sfTrue);
    } if (*walk == 2) {
        *rect_index = 0; *walk = 0;
        sfSprite_setTexture(player->sprite_player,
        player->texture_idle[2], sfTrue);
    } if (*walk == 3) {
        *rect_index = 0; *walk = 0;
        sfSprite_setTexture(player->sprite_player,
        player->texture_idle[1], sfTrue);
    } if (*walk == 4) {
        *rect_index = 0; *walk = 0;
        sfSprite_setTexture(player->sprite_player,
        player->texture_idle[0], sfTrue);
    }
    sfSprite_setTextureRect(player->sprite_player, player->rect);
}
