/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** check_death
*/

#include "player.h"
#include "window.h"
#include "menu.h"

void fade_out_respawn(player_t *player, menu_t *menu)
{
    if (menu->color_fade.a == 255)
        menu->color_fade.a = 254;
    if (menu->color_fade.a > 0) {
        menu->color_fade.a -= 2;
        sfRectangleShape_setFillColor(menu->fade, menu->color_fade);
    }
    if (player->is_dead == 1) {
        sfSprite_setTexture(player->sprite_player, player->texture_idle[0],
            sfTrue);
        sfSprite_setTextureRect(player->sprite_player, player->rect);
        player->state = SIX;
        player->lvl_exp = 0;
    }
    if (menu->color_fade.a == 0) {
        player->respawn_done = 0;
        player->is_dead = 0;
    }
}

void move_all(player_t *player, map_t *map, sfVector2f pos)
{
    int deplace_x = pos.x - sfSprite_getPosition(map->sprite_map[0]).x;
    int deplace_y = pos.y - sfSprite_getPosition(map->sprite_map[0]).y;
    sfSprite_move(map->sprite_map[0], (sfVector2f){0, deplace_y});
    sfSprite_move(map->sprite_map[1], (sfVector2f){0, deplace_y});
    sfSprite_move(map->sprite_map[2], (sfVector2f){0, deplace_y});
    for (int i = 0; i < 5; i++) {
        sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){0, deplace_y});
        sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){0, deplace_y});
        sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){deplace_x, 0});
        sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){deplace_x, 0});
    }
    for (int i = 0; i < 10; i++) {
        sfSprite_move(player->mobs[i]->sprite, (sfVector2f){0, deplace_y});
        sfSprite_move(player->mobs[i]->sprite, (sfVector2f){deplace_x, 0});
    }
    sfSprite_move(map->sprite_map[0], (sfVector2f){deplace_x, 0});
    sfSprite_move(map->sprite_map[1], (sfVector2f){deplace_x, 0});
    sfSprite_move(map->sprite_map[2], (sfVector2f){deplace_x, 0});
}

void respawn_player(player_t *player, map_t *map)
{
    sfVector2f pos = {-4400, -7000};
    move_all(player, map, pos);
}

void change_texture_death(player_t *player)
{
    if (player->state <= 0 && player->is_dead == 0) {
        player->is_dead = 1;
        sfSprite_setTexture(player->sprite_player,
            player->texture_dead, sfTrue);
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite_player, player->rect);
    }
}

void check_death(player_t *player, window_t *window,
    menu_t *menu, map_t *map)
{
    change_texture_death(player);
    if (player->is_dead == 1) {
        if (menu->color_fade.a == 0)
            menu->color_fade.a = 5;
        if (menu->color_fade.a < 255 && player->respawn_done == 0) {
            menu->color_fade.a += 10;
            sfRectangleShape_setFillColor(menu->fade, menu->color_fade);
        }
        if (menu->color_fade.a == 255 && player->respawn_done == 0) {
            respawn_player(player, map);
            player->respawn_done = 1;
        }
        if (player->respawn_done == 1)
            fade_out_respawn(player, menu);
        sfRenderWindow_drawRectangleShape(window->window, menu->fade, NULL);
    }
}
