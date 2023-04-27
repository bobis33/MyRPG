/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "menu.h"

void move_paralax(menu_t *menu)
{
    sfSprite_move(menu->sprite_paralax[0], (sfVector2f){-0.4, 0});
    sfSprite_move(menu->sprite_paralax[1], (sfVector2f){-0.6, 0});
    sfSprite_move(menu->sprite_paralax[2], (sfVector2f){-0.8, 0});
    sfSprite_move(menu->sprite_paralax[3], (sfVector2f){-1, 0});
    sfSprite_move(menu->sprite_paralax[4], (sfVector2f){-1.2, 0});
    sfSprite_move(menu->sprite_paralax[5], (sfVector2f){-1.4, 0});
    sfSprite_move(menu->sprite_paralax[6], (sfVector2f){-1.8, 0});
    sfSprite_move(menu->sprite_paralax[7], (sfVector2f){-2.2, 0});
    sfSprite_move(menu->sprite_paralax_9, (sfVector2f){-2.4, 0});
}
