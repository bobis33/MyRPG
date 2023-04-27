/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** mobs_taking_damage
*/

#include "player.h"

void check_mob_is_dead(player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (player->mobs[i]->hp <= 0) {
            sfSprite_setTexture(player->mobs[i]->sprite,
            player->mobs[i]->texture_death, sfTrue);
            sfSprite_setTextureRect(player->mobs[i]->sprite, player->rect_mobs);
        }
    }
    for (int i = 0; i < 10; i++) {
        if (sfSprite_getTexture(player->mobs[i]->sprite) ==
        player->mobs[i]->texture_death && player->mobs[i]->is_alive == 1 &&
        player->rect_mobs.left == 160) {
            create_music_exp(player);
            sfMusic_play(player->music_exp);
            player->lvl_exp += 1;
            player->mobs[i]->is_alive = 0;
        }
    }
}

void for_mob_x(player_t *player, int i)
{
    if (is_in_range(player, i) == 1) {
        if (player->has_attacked > 0 && player->rect.left == 48) {
            player->mobs[i]->hp--;
            player->has_attacked = 0;
        }
    }
}

void check_mob_is_hit(player_t *player)
{
    for (int i = 0; i < 10; i++) {
        for_mob_x(player, i);
    }
    check_mob_is_dead(player);
}
