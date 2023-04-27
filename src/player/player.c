/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** move_player
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "player.h"

static void move_player(int *walk, map_t *map, player_t *player,
window_t *window)
{
    int count = 0;
    check_change_map(map, window);
    if (sfKeyboard_isKeyPressed(sfKeyLeft)
    || sfKeyboard_isKeyPressed(sfKeyUp)
    || sfKeyboard_isKeyPressed(sfKeyRight)
    || sfKeyboard_isKeyPressed(sfKeyDown))
        count++;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && player->is_attacking == 0
    && is_moveable(sfSprite_getPosition(map->sprite_map[2]), map->image, 1))
        move_up(count, walk, player, map->sprite_map);
    if (sfKeyboard_isKeyPressed(sfKeyDown) && player->is_attacking == 0
    && is_moveable(sfSprite_getPosition(map->sprite_map[2]), map->image, 2))
        move_down(count, walk, player, map->sprite_map);
    if (sfKeyboard_isKeyPressed(sfKeyRight) && player->is_attacking == 0
    && is_moveable(sfSprite_getPosition(map->sprite_map[2]), map->image, 4))
        move_right(count, walk, player, map->sprite_map);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && player->is_attacking == 0
    && is_moveable(sfSprite_getPosition(map->sprite_map[2]), map->image, 3))
        move_left(count, walk, player, map->sprite_map);
}

void is_player_moving(player_t *player, map_t *map,
window_t *window)
{
        sfSprite_setPosition(player->sprite_player,
        (sfVector2f){(1920 / 2) - ((48 * 5) / 2), (1080 / 2) - ((48 * 5) / 2)});
        if (window->is_in_game == 1 && player->is_dead == 0
        && window->is_in_game_menu == 0) {
            move_player(&window->walk, map, player, window);
            check_attack(player);
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse) {
            player_idle(&window->walk, &window->rect_index, player);
            walk_off(player);
        }
}

static void move_player_epi(int *walk, map_t *map, player_t *player,
window_t *window)
{
    int count = 0;
    check_return_in_map(map, window);
    if (sfKeyboard_isKeyPressed(sfKeyLeft)
    || sfKeyboard_isKeyPressed(sfKeyUp)
    || sfKeyboard_isKeyPressed(sfKeyRight)
    || sfKeyboard_isKeyPressed(sfKeyDown))
        count++;
    if (sfKeyboard_isKeyPressed(sfKeyUp)
    && is_moveable(sfSprite_getPosition(map->sprite_epi[2]), map->image_epi, 1))
        move_up(count, walk, player, map->sprite_epi);
    if (sfKeyboard_isKeyPressed(sfKeyDown)
    && is_moveable(sfSprite_getPosition(map->sprite_epi[2]), map->image_epi, 2))
        move_down(count, walk, player, map->sprite_epi);
    if (sfKeyboard_isKeyPressed(sfKeyRight)
    && is_moveable(sfSprite_getPosition(map->sprite_epi[2]), map->image_epi, 4))
        move_right(count, walk, player, map->sprite_epi);
    if (sfKeyboard_isKeyPressed(sfKeyLeft)
    && is_moveable(sfSprite_getPosition(map->sprite_epi[2]), map->image_epi, 3))
        move_left(count, walk, player, map->sprite_epi);
}

void is_player_moving_epi(player_t *player, map_t *map,
window_t *window)
{
        sfSprite_setPosition(player->sprite_player,
        (sfVector2f){(1920 / 2) - ((48 * 5) / 2), (1080 / 2) - ((48 * 5) / 2)});
        if (window->is_in_game == 1) {
            move_player_epi(&window->walk, map, player, window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse) {
            player_idle(&window->walk, &window->rect_index, player);
            walk_off(player);
        }
}
