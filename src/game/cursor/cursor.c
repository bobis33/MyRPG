/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** cursor
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "window.h"


void case_cursor(window_t *window)
{
    float pos_x = 0;
    float pos_y = 0;
    pos_x =
    (sfMouse_getPositionRenderWindow(window->window).x);
    pos_y =
    (sfMouse_getPositionRenderWindow(window->window).y);
    sfVector2f pos = (sfVector2f){pos_x, pos_y};
    sfSprite_setPosition(window->sprite_cursor, pos);
    sfRenderWindow_drawSprite(window->window, window->sprite_cursor, NULL);
}

void create_cursor(window_t *window)
{
    float pos_x = 0;
    float pos_y = 0;
    pos_x =
    (sfMouse_getPositionRenderWindow(window->window).x);
    pos_y =
    (sfMouse_getPositionRenderWindow(window->window).y);
    sfVector2f pos = (sfVector2f){pos_x, pos_y};
    sfVector2f scale = {0.09, 0.09};
    window->texture_cursor =
    sfTexture_createFromFile("assets/cursor.png", NULL);
    window->sprite_cursor = sfSprite_create();
    sfSprite_setTexture(window->sprite_cursor, window->texture_cursor, sfTrue);
    sfSprite_setPosition(window->sprite_cursor, pos);
    sfSprite_setScale(window->sprite_cursor, scale);
}
