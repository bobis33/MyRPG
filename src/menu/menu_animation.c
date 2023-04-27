/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu_animation
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "utils.h"
#include "menu.h"
#include "player.h"
#include "map.h"
#include "game.h"

void animation_menu_1(window_t *window, player_t *player, menu_t *menu)
{
    if (window->menu_anim_1 == 1) {
        sfSprite_move(menu->sprite_title, (sfVector2f){-2.2, 0});
        sfSprite_move(player->sprite_player, (sfVector2f){3, 0});
        window->menu_anim_fade = 1;
        if (menu->color_fade.a < 255
        && sfSprite_getPosition(player->sprite_player).x > 1300) {
            menu->color_fade.a += 2;
            sfRectangleShape_setFillColor(menu->fade, menu->color_fade);
        }
    }
    if (sfSprite_getPosition(player->sprite_player).x > 1920) {
        sfSprite_setTexture(player->sprite_player,
        player->texture_walk[0], sfTrue);
        sfSprite_setTextureRect(player->sprite_player, player->rect);
        window->is_in_menu = 0;
        window->menu_anim_1 = 0;
        window->menu_anim_2 = 1;
    }
}

void animation_menu_2(window_t *window, player_t *player,
menu_t *menu, map_t *map)
{
    if (window->menu_anim_2 == 1) {
        if (menu->color_fade.a > 0) {
            menu->color_fade.a -= 5;
            sfRectangleShape_setFillColor(menu->fade, menu->color_fade);
        }
        if (replace_map(map, player) == 1) {
            sfSprite_setTexture(player->sprite_player,
            player->texture_idle[1], sfTrue);
            sfSprite_setTextureRect(player->sprite_player, player->rect);
            window->menu_anim_2 = 0;
            window->is_in_game = 1;
            window->menu_anim_fade = 0;
        }
        if (window->music_state == 1) {
            change_music(window, "assets/music/ingame.ogg");
            window->music_state = 2;
        }
    }
}

void mob_update(window_t *window, player_t *player)
{
    if (window->is_in_menu == 0 && window->seconds > 0.01 &&
        window->attack_index >= 100 && player->rect_mobs.left == 0) {
        window->attack_index = 0;
        check_mob_attack(player);
        check_mob_respawn(player);
    }
    check_mob_is_hit(player);
    check_stop_mob_attack(player);
}

void setrect(player_t *player)
{
    sfSprite_setTextureRect(player->sprite_player, player->rect);
    for (int i = 0; i < 8; i++)
        sfSprite_setTextureRect(player->pnj[i]->sprite_pnj, player->rect);
    for (int i = 0; i < 10; i++)
        if (player->mobs[i]->is_alive == 1)
            sfSprite_setTextureRect(player->mobs[i]->sprite,
                player->rect_mobs);
}

void animation_player_menu(window_t *window, player_t *player)
{
    if (window->seconds > 0.01) {
        window->rect_index++; window->attack_index++;
    }
    if (window->seconds > 0.01 && window->rect_index == 8) {
        window->rect_index = 0;
        setrect(player);
        player->rect_mobs.left += 32; player->rect.left += 48;
        if (player->rect_mobs.left >= 192)
            player->rect_mobs.left = 0;
        if (player->rect.left >= 288)
            player->rect.left = 0;
    }
    mob_update(window, player);
    sfClock_restart(window->clock);
}
