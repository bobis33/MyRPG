/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** case_hud
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>

/* LOCAL INCLUDES */
#include "menu.h"
#include "player.h"


void health_bar_case(player_t *player)
{
    if (player->state == SIX)
        sfSprite_setTextureRect(player->sprite_health,
        (sfIntRect) {0, 20, 17, 4});
    if (player->state == FIVE)
        sfSprite_setTextureRect(player->sprite_health,
        (sfIntRect) {0, 16, 17, 4});
    if (player->state == FOUR)
        sfSprite_setTextureRect(player->sprite_health,
        (sfIntRect) {0, 12, 17, 4});
    if (player->state == THREE)
        sfSprite_setTextureRect(player->sprite_health,
        (sfIntRect) {0, 8, 17, 4});
    if (player->state == TWO)
        sfSprite_setTextureRect(player->sprite_health,
        (sfIntRect) {0, 4, 17, 4});
    if (player->state == ONE)
        sfSprite_setTextureRect(player->sprite_health,
        (sfIntRect) {0, 0, 17, 4});
}

void case_hud(window_t *window, player_t *player)
{
    sfRenderWindow_drawSprite(window->window, player->sprite_health, NULL);
    game_inventory_draw(window, player);
    health_bar_case(player);
    sfRenderWindow_drawSprite(window->window, player->sprite_exp, NULL);
    sfRenderWindow_drawText(window->window, player->text_exp, NULL);
}
