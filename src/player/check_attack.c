/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** check_attack
*/


#include "player.h"


void stop_rect_attack(player_t *player)
{
    if (player->rect.left >= 192 &&
    sfSprite_getTexture(player->sprite_player) == player->texture_attack[0]) {
        sfSprite_setTexture(player->sprite_player,player->texture_idle[0],
        sfTrue); player->is_attacking = 0; player->has_attacked = 0;
    } if (player->rect.left >= 192 &&
    sfSprite_getTexture(player->sprite_player) == player->texture_attack[1]) {
        sfSprite_setTexture(player->sprite_player, player->texture_idle[1],
        sfTrue); player->is_attacking = 0; player->has_attacked = 0;
    } if (player->rect.left >= 192 &&
    sfSprite_getTexture(player->sprite_player) == player->texture_attack[2]) {
        sfSprite_setTexture(player->sprite_player, player->texture_idle[2],
        sfTrue); player->is_attacking = 0; player->has_attacked = 0;
    } if (player->rect.left >= 192 &&
    sfSprite_getTexture(player->sprite_player) == player->texture_attack[3]) {
        sfSprite_setTexture(player->sprite_player, player->texture_idle[3],
        sfTrue); player->is_attacking = 0; player->has_attacked = 0;
    }
    sfSprite_setTextureRect(player->sprite_player, player->rect);
}

void attack(player_t *player)
{
    pos_attack_1(player);
    pos_attack_2(player);
    pos_attack_3(player);
    pos_attack_4(player);
}

void check_bug_attack(player_t *player)
{
    if (player->is_attacking > 0
    && (sfSprite_getTexture(player->sprite_player) == player->texture_idle[0]
    || sfSprite_getTexture(player->sprite_player) == player->texture_idle[1]
    || sfSprite_getTexture(player->sprite_player) == player->texture_idle[2]
    || sfSprite_getTexture(player->sprite_player) == player->texture_idle[3])) {
        player->is_attacking = 0;
        player->has_attacked = 0;
    }
}

void check_bug_deplacement(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)
    && sfSprite_getTexture(player->sprite_player) == player->texture_idle[0]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[1], sfTrue);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)
    && sfSprite_getTexture(player->sprite_player) == player->texture_idle[1]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[0], sfTrue);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)
    && sfSprite_getTexture(player->sprite_player) == player->texture_idle[2]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[3], sfTrue);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)
    && sfSprite_getTexture(player->sprite_player) == player->texture_idle[3]) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[2], sfTrue);
    }
}

void check_attack(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)
    && player->is_attacking == 0 && player->boxes->items[0] == 1) {
        attack_sound(player);
        player->rect.left = 0;
        attack(player);
        sfSprite_setTextureRect(player->sprite_player, player->rect);
    }
    stop_rect_attack(player);
    check_bug_deplacement(player);
    check_bug_attack(player);
    sfSprite_setTextureRect(player->sprite_player, player->rect);
}
