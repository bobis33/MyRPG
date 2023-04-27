/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** mobs
*/

#include "player.h"
#include <stdlib.h>

void setpos_mob(player_t *player, int i)
{
    if (i == 0)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){100, 100});
    if (i == 1)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){-2200, 200});
    if (i == 2)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){-3200, 600});
    if (i == 3)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){-1500, 500});
    if (i == 4)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){-4000, 300});
    if (i == 5)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){1800, -100});
    if (i == 6)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){2600, 500});
    if (i == 7)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){3900, 0});
    if (i == 8)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){5400, 100});
    if (i == 9)
        sfSprite_setPosition(player->mobs[i]->sprite, (sfVector2f){4600, 600});
}

void attribute_texture_mob(player_t *player, int i)
{
    player->mobs[i]->texture = sfTexture_createFromFile
    ("assets/mobs/mob_animation.png", NULL);
    player->mobs[i]->texture_attack = sfTexture_createFromFile
    ("assets/mobs/mob_animation_attack.png", NULL);
    player->mobs[i]->texture_death = sfTexture_createFromFile
    ("assets/mobs/mob_animation_dead.png", NULL);
    player->mobs[i]->texture_left = sfTexture_createFromFile
    ("assets/mobs/mob_animation_left.png", NULL);
    player->mobs[i]->texture_attack_left = sfTexture_createFromFile
    ("assets/mobs/mob_animation_attack_left.png", NULL);
}

void create_mobs(player_t *player)
{
    player->mobs = malloc(sizeof(mobs_t *) * 10);
    for (int i = 0; i < 10; i++) {
        player->mobs[i] = malloc(sizeof(mobs_t));
        attribute_texture_mob(player, i);
        player->mobs[i]->sprite = sfSprite_create();
        sfSprite_setTexture(player->mobs[i]->sprite,
        player->mobs[i]->texture, sfTrue);
        setpos_mob(player, i);
        sfSprite_setScale(player->mobs[i]->sprite, (sfVector2f){5, 5});
        player->mobs[i]->rect = (sfIntRect){0, 0, 32, 32};
        player->mobs[i]->hp = 3;
        player->mobs[i]->is_alive = 1;
        player->mobs[i]->timer_revive = 0;
    }
}

void change_dir(player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (player->mobs[i]->is_alive == 1 && sfSprite_getPosition
            (player->mobs[i]->sprite).x > sfSprite_getPosition
            (player->sprite_player).x + 50 && sfSprite_getTexture
            (player->mobs[i]->sprite) == player->mobs[i]->texture) {
            sfSprite_setTexture(player->mobs[i]->sprite,
            player->mobs[i]->texture_left, sfTrue);
            sfSprite_setTextureRect(player->mobs[i]->sprite, player->rect_mobs);
        }
        if (player->mobs[i]->is_alive == 1 && sfSprite_getPosition
            (player->mobs[i]->sprite).x < sfSprite_getPosition
            (player->sprite_player).x + 50 && sfSprite_getTexture
            (player->mobs[i]->sprite) == player->mobs[i]->texture_left) {
            sfSprite_setTexture(player->mobs[i]->sprite,
            player->mobs[i]->texture, sfTrue);
            sfSprite_setTextureRect(player->mobs[i]->sprite, player->rect_mobs);
        }
    }
}

void draw_mobs(window_t *window, player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (player->mobs[i]->is_alive == 1) {
            change_dir(player);
            sfRenderWindow_drawSprite(window->window, player->mobs[i]->sprite,
            NULL);
        }
    }
}
