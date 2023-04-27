/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_init
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "window.h"
#include "menu.h"
#include "player.h"
#include "map.h"
#include "game.h"
#include "button.h"
#include "utils.h"


void game_init(window_t *window, menu_t *menu,
map_t *map, player_t *player)
{
    menu->color_fade = (sfColor) {0, 0, 0, 1};
    sfVideoMode mode = {1920, 1080, 32};
    window->window = sfRenderWindow_create(mode,
    "MSC QUEST", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    ini_struct_window(window);
    ini_struct_player(window, player);
    create_game(window, menu, map, player);
    player->quest_advencement = 0;
}

static void loop_event(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)
    && window->is_left == 0) {
        if (window->event.type == sfEvtClosed)
            window->is_left = 1;
        if (sfKeyboard_isKeyPressed(sfKeyEscape)
        && window->is_in_game == 1 && window->is_in_settings == 0) {
            window->is_in_game_menu = 1;
        }
        scroll_case(window);
    }
}

void game_loop(window_t *window, menu_t *menu, map_t *map, player_t *player)
{
    while (sfRenderWindow_isOpen(window->window) && window->is_left == 0) {
        window->seconds =
        sfClock_getElapsedTime(window->clock).microseconds / 1000000.0;
        loop_event(window);
        animation_menu_1(window, player, menu);
        animation_player_menu(window, player);
        animation_menu_2(window, player, menu, map);
        create_game_layer_1(window, menu, map, player);
        create_game_layer_2(window, menu, map, player);
        check_death(player, window, menu, map);
        sfText_setString(player->text_exp, my_itoa(player->lvl_exp));
        sfText_setString(player->text_force, my_itoa(player->force));
        button_case_menu(window, menu);
        game_menu(window, menu, player);
        case_cursor(window);
        sfRenderWindow_display(window->window);
        sfRenderWindow_clear(window->window, sfBlack);
        check_update_force(player, window);
    }
}
