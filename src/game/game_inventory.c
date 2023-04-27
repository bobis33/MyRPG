/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_inventory
*/

#include <stdlib.h>
#include "game.h"

void game_inventory_draw(window_t *window, player_t *player)
{
    int i = 0;
    for (i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(window->window,
            player->boxes->invent[i]->box, NULL);
    }
    for (i = 0; i < 1; i++) {
        if (player->boxes->items[0] == 1)
            sfRenderWindow_drawSprite(window->window,
                player->boxes->invent[0]->sprite_sword, NULL);
        if (player->boxes->items[1] == 1)
            sfRenderWindow_drawSprite(window->window,
                player->boxes->invent[1]->sprite_grimoire, NULL);
        if (player->boxes->items[2] == 1)
            sfRenderWindow_drawSprite(window->window,
                player->boxes->invent[2]->sprite_shoe, NULL);
    }
}

void game_inventory_create(sfVector2f size, int i, inventory_t *invent)
{
    invent->pos = (sfVector2f) {25, (i * 120) + 25};
    invent->box = sfRectangleShape_create();
    sfRectangleShape_setSize(invent->box, size);
    sfRectangleShape_setPosition(invent->box, invent->pos);
    sfRectangleShape_setFillColor(invent->box, (sfColor) {0, 0, 0, 50});
    sfRectangleShape_setOutlineThickness(invent->box, 3);
    sfRectangleShape_setOutlineColor(invent->box,
        (sfColor) {255, 255, 255, 100});
    inventory_slot1(invent);
    inventory_slot2(invent);
    inventory_slot3(invent);
}

void game_inventory(player_t *player)
{
    sfVector2f size = {100, 100};
    player->boxes = malloc(sizeof(boxes_t));
    player->boxes->invent = malloc(sizeof(inventory_t *) * 4);
    player->boxes->items = malloc(sizeof(int) * 3);

    player->boxes->invent[3] = NULL;
    for (int i = 0; i < 3; i++) {
        player->boxes->items[i] = 0;
        player->boxes->invent[i] = malloc(sizeof(inventory_t));
        game_inventory_create(size, i, player->boxes->invent[i]);
    }
}
