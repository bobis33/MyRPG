/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** create_pnj_talk
*/

#include "player.h"
/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

void create_talk(sfTexture **texture, sfSprite **sprite)
{
    *texture = sfTexture_createFromFile("assets/talk/dialog_box.png", NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, (sfVector2f){0, 0});
    sfSprite_setScale(*sprite, (sfVector2f){6, 6});
}
