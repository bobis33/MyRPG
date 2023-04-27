/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** mobs_attack
*/

#include "player.h"

int is_in_range(player_t *player, int i)
{
    sfVector2f mid_pos = sfSprite_getPosition(player->sprite_player);
    if (sfSprite_getPosition(player->mobs[i]->sprite).x
    < mid_pos.x + 180 && sfSprite_getPosition(player->mobs[i]->sprite).x
    > mid_pos.x - 80 && sfSprite_getPosition(player->mobs[i]->sprite).y
    < mid_pos.y + 220 && sfSprite_getPosition(player->mobs[i]->sprite).y
    > mid_pos.y - 40) {
        return 1;
    }
    return 0;
}

void mob_attack(player_t *player, int i)
{
    if (sfSprite_getTexture(player->mobs[i]->sprite) ==
        player->mobs[i]->texture) {
        sfSprite_setTexture(player->mobs[i]->sprite,
        player->mobs[i]->texture_attack, sfTrue);
    } else if (sfSprite_getTexture(player->mobs[i]->sprite) ==
        player->mobs[i]->texture_left) {
        sfSprite_setTexture(player->mobs[i]->sprite,
        player->mobs[i]->texture_attack_left, sfTrue);
    }
    blob_sound(player);
    sfSprite_setTextureRect(player->mobs[i]->sprite, player->rect_mobs);
}

void check_stop_mob_attack(player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (player->rect_mobs.left == 0 && is_in_range(player, i) == 0
        && player->mobs[i]->is_alive == 1 && sfSprite_getTexture
        (player->mobs[i]->sprite) == player->mobs[i]->texture_attack) {
            sfSprite_setTexture(player->mobs[i]->sprite,
            player->mobs[i]->texture, sfTrue);
            sfSprite_setTextureRect(player->mobs[i]->sprite, player->rect_mobs);
        }
        if (player->rect_mobs.left == 0 && is_in_range(player, i)
        == 0 && player->mobs[i]->is_alive == 1 && sfSprite_getTexture
        (player->mobs[i]->sprite) == player->mobs[i]->texture_attack_left) {
            sfSprite_setTexture(player->mobs[i]->sprite,
            player->mobs[i]->texture_left, sfTrue);
            sfSprite_setTextureRect(player->mobs[i]->sprite, player->rect_mobs);
        }

    }
}

void check_mob_attack(player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (is_in_range(player, i) == 1 &&
        player->mobs[i]->is_alive == 1) {
            mob_attack(player, i);
            player->state--;
        }
    }
}
