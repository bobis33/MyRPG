/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** inventory_slots
*/

#include "game.h"

void inventory_slot1(inventory_t *invent)
{
    invent->texture_sword =
        sfTexture_createFromFile("assets/player/Sword.png", NULL);
    invent->sprite_sword = sfSprite_create();
    sfSprite_setTexture(invent->sprite_sword, invent->texture_sword, sfTrue);
    sfSprite_setPosition(invent->sprite_sword,
        (sfVector2f) {invent->pos.x + 7, invent->pos.y + 7});
    sfSprite_setScale(invent->sprite_sword, (sfVector2f) {5.5, 5.5});
}

void inventory_slot2(inventory_t *invent)
{
    invent->texture_grimoire =
        sfTexture_createFromFile("assets/player/Grimoire.png", NULL);
    invent->sprite_grimoire = sfSprite_create();
    sfSprite_setTexture(invent->sprite_grimoire,
        invent->texture_grimoire, sfTrue);
    sfSprite_setPosition(invent->sprite_grimoire,
        (sfVector2f) {invent->pos.x + 7, invent->pos.y + 127});
    sfSprite_setScale(invent->sprite_grimoire, (sfVector2f) {5.5, 5.5});
}

void inventory_slot3(inventory_t *invent)
{
    invent->texture_shoe =
        sfTexture_createFromFile("assets/player/Shoe.png", NULL);
    invent->sprite_shoe = sfSprite_create();
    sfSprite_setTexture(invent->sprite_shoe, invent->texture_shoe, sfTrue);
    sfSprite_setPosition(invent->sprite_shoe,
        (sfVector2f) {invent->pos.x + 7, invent->pos.y + 247});
    sfSprite_setScale(invent->sprite_shoe, (sfVector2f) {5.5, 5.5});
}
