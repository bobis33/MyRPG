/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** ratio_window
*/


#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include "window.h"


void get_ratio(window_t *window)
{
    window->ratio_x = (1920 / (float) sfRenderWindow_getSize(window->window).x);
    window->ratio_y = (1080 / (float) sfRenderWindow_getSize(window->window).y);
}
