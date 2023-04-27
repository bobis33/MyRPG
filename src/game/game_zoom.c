/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** game_zoom
*/

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** game_zoom
*/

#include "player.h"

void create_zoom(window_t *window)
{
    window->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    sfView_zoom(window->view, window->zoom_level);
}

void scroll_case(window_t *window)
{
    double old_zoom = window->zoom_level;
    if (window->event.type == sfEvtMouseWheelScrolled) {
        if (window->is_in_menu == 1)
            return;
        if (window->event.mouseWheelScroll.delta > 0
        && window->zoom_level < 1.0)
            window->zoom_level += 0.1;
        if (window->event.mouseWheelScroll.delta < 0
        && window->zoom_level > 0.5)
            window->zoom_level -= 0.1;
        if (old_zoom != window->zoom_level)
            sfView_zoom(window->view, window->zoom_level);
    }
}
