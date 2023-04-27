/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_layer
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>

/* LOCAL INCLUDES */
#include "menu.h"
#include "player.h"
#include "game.h"

void set_pos_paralax(menu_t *menu)
{
    if (sfSprite_getPosition(menu->sprite_paralax[0]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[0], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax[1]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[1], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax[2]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[2], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax[3]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[3], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax[4]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[4], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax[5]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[5], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax[6]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[6], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax[7]).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax[7], (sfVector2f){0, 0});
    if (sfSprite_getPosition(menu->sprite_paralax_9).x < -1920)
        sfSprite_setPosition(menu->sprite_paralax_9, (sfVector2f){0, 0});
}

void for_house1(window_t *window, map_t *map, player_t *player)
{
    is_player_moving_epi(player, map, window);
    is_pnj_bubble(player);
    is_pnj_talk(player, window);
    sfRenderWindow_drawSprite(window->window, map->sprite_epi[0], NULL);
    draw_pnj(player, window);
}

void create_game_layer_1(window_t *window, menu_t *menu,
map_t *map, player_t *player)
{
    if (window->is_in_menu == 1) {
        draw_menu(menu, window->window, menu->sprite_title);
        set_pos_paralax(menu);
        move_paralax(menu);
    } if (window->is_in_menu == 0) {
        is_player_moving(player, map, window);
        is_pnj_bubble(player);
        is_pnj_talk(player, window);
        sfRenderWindow_drawSprite(window->window, map->sprite_map[0], NULL);
        draw_pnj(player, window);
        draw_mobs(window, player);
    } if (window->is_in_menu == 2)
        for_house1(window, map, player);
    check_quest_advencement(player);
    sfRenderWindow_drawSprite(window->window, player->sprite_player, NULL);
}

void create_game_layer_2(window_t *window, menu_t *menu,
map_t *map, player_t *player)
{
    if (window->is_in_menu == 1) {
        sfRenderWindow_drawSprite(window->window, menu->sprite_paralax_9, NULL);
    } if (window->is_in_menu == 0) {
        sfRenderWindow_drawSprite(window->window, map->sprite_map[1], NULL);
        case_hud(window, player);
        draw_bubble(player, window);
        draw_talk(menu, player, window);
    } if (window->is_in_menu == 2) {
        sfRenderWindow_drawSprite(window->window, map->sprite_epi[1], NULL);
        case_hud(window, player);
        draw_bubble(player, window);
        draw_talk(menu, player, window);
    } if (window->menu_anim_fade == 1)
        sfRenderWindow_drawRectangleShape(window->window, menu->fade, NULL);
}
