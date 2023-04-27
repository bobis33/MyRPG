/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** button
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "menu.h"


#ifndef BUTTON_H_
    #define BUTTON_H_
    typedef struct button {
        sfTexture **texture_button;
        sfSprite **sprite_button;
        sfIntRect rect;
    } button_t;
    void button_play(window_t *window, button_t *button,
    sfVector2i pos_mouse);
    void button_settings(window_t *window, button_t *button,
    sfVector2i pos_mouse);
    void button_exit(window_t *window, button_t *button,
    sfVector2i pos_mouse);
    void button_how_to_play(window_t *window, button_t *button,
    sfVector2i pos_mouse);
#endif /* !BUTTON_H_ */
