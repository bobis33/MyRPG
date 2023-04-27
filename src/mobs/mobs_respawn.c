/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** mobs_respawn
*/

#include "player.h"

void check_mob_respawn(player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (player->mobs[i]->is_alive == 0) {
            player->mobs[i]->timer_revive += 1;
        }
        if (player->mobs[i]->timer_revive == 20) {
            sfSprite_setTexture(player->mobs[i]->sprite,
                player->mobs[i]->texture, sfTrue);
            sfSprite_setTextureRect(player->mobs[i]->sprite, player->rect_mobs);
            player->mobs[i]->is_alive = 1;
            player->mobs[i]->hp = player->max_hp_mob;
            player->mobs[i]->timer_revive = 0;
        }
    }
}
