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

void draw_menu(menu_t *menu, sfRenderWindow *window, sfSprite *title)
{
    sfRenderWindow_drawSprite(window, menu->sprite_background, NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[0], NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[1], NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[2], NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[3], NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[4], NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[5], NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[6], NULL);
    sfRenderWindow_drawSprite(window, menu->sprite_paralax[7], NULL);
    sfRenderWindow_drawSprite(window, title, NULL);
}
