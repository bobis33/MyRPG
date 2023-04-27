/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** check_pos_attack
*/


#include "player.h"


void pos_attack_1(player_t *player)
{
    if (sfSprite_getTexture(player->sprite_player) == player->texture_idle[0]
    || sfSprite_getTexture(player->sprite_player) == player->texture_walk[1]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_attack[0], sfTrue);
        player->is_attacking = 1;
        player->has_attacked = 1;
    }
}

void pos_attack_2(player_t *player)
{
    if (sfSprite_getTexture(player->sprite_player) == player->texture_idle[1]
    || sfSprite_getTexture(player->sprite_player) == player->texture_walk[0]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_attack[1], sfTrue);
        player->is_attacking = 2;
        player->has_attacked = 1;
    }
}

void pos_attack_3(player_t *player)
{
    if (sfSprite_getTexture(player->sprite_player) == player->texture_idle[2]
    || sfSprite_getTexture(player->sprite_player) == player->texture_walk[3]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_attack[2], sfTrue);
        player->is_attacking = 3;
        player->has_attacked = 1;
    }
}

void pos_attack_4(player_t *player)
{
    if (sfSprite_getTexture(player->sprite_player) == player->texture_idle[3]
    || sfSprite_getTexture(player->sprite_player) == player->texture_walk[2]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_attack[3], sfTrue);
        player->is_attacking = 4;
        player->has_attacked = 1;
    }
}
