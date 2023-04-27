/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** player_create
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "player.h"

void create_player(sfTexture *texture, sfSprite **sprite)
{
    sfVector2f pos = {815, 720};
    sfVector2f scale = {5, 5};
    sfIntRect pos_rect = {0, 0, 48, 48};

    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
    sfSprite_setTextureRect(*sprite, pos_rect);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

void create_health_bar(player_t *player)
{
    sfVector2f pos = {1780, 5};
    sfVector2f scale = {8, 8};
    sfIntRect pos_rect = {0, 900, 635, 170};

    player->texture_health =
    sfTexture_createFromFile("assets/player/health_bar.png", NULL);
    player->sprite_health = sfSprite_create();
    sfSprite_setTexture(player->sprite_health, player->texture_health, sfTrue);
    sfSprite_setTextureRect(player->sprite_health, pos_rect);
    sfSprite_setPosition(player->sprite_health, pos);
    sfSprite_setScale(player->sprite_health, scale);
}
