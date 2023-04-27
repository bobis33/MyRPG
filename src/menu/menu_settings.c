/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu_settings
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>

/* LOCAL INCLUDES */
#include "window.h"
#include "menu.h"


static void create_text(menu_t *menu)
{
    sfVector2f pos_text = {780, 20};

    menu->text_settings = sfText_create();
    menu->font_settings = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText_setFont(menu->text_settings, menu->font_settings);
    sfText_setString(menu->text_settings, "SETTINGS");
    sfText_setCharacterSize(menu->text_settings, 75);
    sfText_setPosition(menu->text_settings, pos_text);
}

void create_settings_fade(menu_t *menu)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {1920, 1080};
    sfColor color = {0, 0, 0, 220};

    menu->rect_settings = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->rect_settings, size);
    sfRectangleShape_setPosition(menu->rect_settings, pos);
    sfRectangleShape_setFillColor(menu->rect_settings, color);
    create_text(menu);
}

void menu_settings(window_t *window, menu_t *menu)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window->window);
    if (window->is_in_settings == 1) {
        sfRenderWindow_drawRectangleShape(window->window,
        menu->rect_settings, NULL);
        sfRenderWindow_drawText(window->window, menu->text_settings, NULL);
        sfRenderWindow_drawSprite(window->window,
        menu->button->sprite_button[4], NULL);
        if (pos_mouse.x > 1857 && pos_mouse.x < 1908
        && pos_mouse.y > 16 && pos_mouse.y < 65
        && sfMouse_isButtonPressed(sfMouseLeft) == true)
            window->is_in_settings = 0;
    }
}
