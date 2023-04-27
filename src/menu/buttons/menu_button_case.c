/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu_button_case
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>

/* LOCAL INCLUDES */
#include "menu.h"
#include "button.h"


static void draw_button(window_t *window, button_t *button)
{
    if (window->menu_anim_1 == 0
    && window->menu_anim_2 == 0
    && window->is_in_game == 0) {
        sfRenderWindow_drawSprite(window->window,
        button->sprite_button[0], NULL);
        sfRenderWindow_drawSprite(window->window,
        button->sprite_button[1], NULL);
        sfRenderWindow_drawSprite(window->window,
        button->sprite_button[2], NULL);
        sfRenderWindow_drawSprite(window->window,
        button->sprite_button[3], NULL);
    }
}

void button_case_menu(window_t *window, menu_t *menu)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window->window);
    button_play(window, menu->button, pos_mouse);
    button_settings(window, menu->button, pos_mouse);
    button_exit(window, menu->button, pos_mouse);
    button_how_to_play(window, menu->button, pos_mouse);
    draw_button(window, menu->button);
    menu_settings(window, menu);
    menu_how_play(window, menu);
}
