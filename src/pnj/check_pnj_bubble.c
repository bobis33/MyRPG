/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** check_pnj_bubble
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "player.h"

void check_pnj_bubble(player_t *player, int i)
{
    if (sfSprite_getPosition(player->pnj[i]->sprite_pnj).x <= 840 + 150 &&
    sfSprite_getPosition(player->pnj[i]->sprite_pnj).x >= 840 - 150 &&
    sfSprite_getPosition(player->pnj[i]->sprite_pnj).y <= 420 + 150 &&
    sfSprite_getPosition(player->pnj[i]->sprite_pnj).y >= 420 - 150) {
        player->pnj[i]->is_bubble = 1;
    } else {
        player->pnj[i]->is_bubble = 0;
        player->pnj[i]->is_talk = 0;
    }
}

void is_pnj_bubble(player_t *player)
{
    for (int i = 0; i < 8; i++) {
        check_pnj_bubble(player, i);
    }
}
