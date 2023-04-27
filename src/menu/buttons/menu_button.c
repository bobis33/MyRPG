/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu_button
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>

/* LOCAL INCLUDES */
#include "menu.h"
#include "button.h"



void button_exit(window_t *window, button_t *button, sfVector2i pos_mouse)
{
    sfIntRect pos_rect_origin = {0, 49, 190, 49};
    sfIntRect pos_rect_second = {0, 98, 190, 45};
    sfIntRect pos_rect_third = {0, 143, 190, 45};
    if ((window->menu_anim_1 == 0 && window->menu_anim_2 == 0
    && window->is_in_game == 0 && window->is_in_settings == 0
    && window->is_in_how_play == 0
    && pos_mouse.x > 1420 && pos_mouse.x < 1704)
    && pos_mouse.y > 450 && pos_mouse.y < 522) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
            sfSprite_setTextureRect(button->sprite_button[2],
            pos_rect_second);
            window->is_left = 1;
        } else {
            sfSprite_setTextureRect(button->sprite_button[2],
            pos_rect_third);
        }
    } else {
        sfSprite_setTextureRect(button->sprite_button[2],
        pos_rect_origin);
    }
}

void button_settings(window_t *window, button_t *button,
sfVector2i pos_mouse)
{
    sfIntRect pos_rect_origin = {0, 49, 190, 49};
    sfIntRect pos_rect_second = {0, 98, 190, 45};
    sfIntRect pos_rect_third = {0, 143, 190, 45};
    if ((window->menu_anim_1 == 0 && window->menu_anim_2 == 0
    && window->is_in_game == 0 && window->is_in_settings == 0
    && window->is_in_how_play == 0
    && pos_mouse.x > 1020 && pos_mouse.x < 1304)
    && pos_mouse.y > 450 && pos_mouse.y < 522) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
            sfSprite_setTextureRect(button->sprite_button[1],
            pos_rect_second);
            window->is_in_settings = 1;
        } else {
            sfSprite_setTextureRect(button->sprite_button[1],
            pos_rect_third);
        }
    } else if (window->is_in_menu == 1) {
        sfSprite_setTextureRect(button->sprite_button[1], pos_rect_origin);
    }
}

void button_how_to_play(window_t *window, button_t *button,
sfVector2i pos_mouse)
{
    sfIntRect pos_rect_origin = {0, 49, 190, 49};
    sfIntRect pos_rect_second = {0, 98, 190, 45};
    sfIntRect pos_rect_third = {0, 143, 190, 45};
    if ((window->menu_anim_1 == 0 && window->menu_anim_2 == 0
    && window->is_in_game == 0 && window->is_in_settings == 0
    && window->is_in_how_play == 0
    && pos_mouse.x > 620 && pos_mouse.x < 904)
    && pos_mouse.y > 450 && pos_mouse.y < 522) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
            sfSprite_setTextureRect(button->sprite_button[3],
            pos_rect_second);
            window->is_in_how_play = 1;
        } else {
            sfSprite_setTextureRect(button->sprite_button[3],
            pos_rect_third);
        }
    } else {
        sfSprite_setTextureRect(button->sprite_button[3],
        pos_rect_origin);
    }
}

void button_play(window_t *window, button_t *button, sfVector2i pos_mouse)
{
    sfIntRect pos_rect_origin = {0, 49, 190, 49};
    sfIntRect pos_rect_second = {0, 98, 190, 45};
    sfIntRect pos_rect_third = {0, 143, 190, 45};
    if ((window->menu_anim_1 == 0 && window->menu_anim_2 == 0
    && window->is_in_game == 0 && window->is_in_settings == 0
    && window->is_in_how_play == 0
    && pos_mouse.x > 220 && pos_mouse.x < 504)
    && pos_mouse.y > 450 && pos_mouse.y < 522) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
            sfSprite_setTextureRect(button->sprite_button[0],
            pos_rect_second);
            window->menu_anim_1 = 1;
        } else {
            sfSprite_setTextureRect(button->sprite_button[0],
            pos_rect_third);
        }
    } else {
        sfSprite_setTextureRect(button->sprite_button[0],
        pos_rect_origin);
    }
}
