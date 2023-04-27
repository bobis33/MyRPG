/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** move_pnj
*/

#include "player.h"

void move_up_pnj(player_t *player, int speed)
{
    if (*player->is_in_menu_p == 0)
        for (int i = 0; i < 5; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){0, speed});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){0, speed});
    }
    if (*player->is_in_menu_p == 2)
        for (int i = 5; i < 8; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){0, speed});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){0, speed});
    }
}

void move_down_pnj(player_t *player, int speed)
{
    if (*player->is_in_menu_p == 0)
        for (int i = 0; i < 5; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){0, -speed});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){0, -speed});
    }
    if (*player->is_in_menu_p == 2)
        for (int i = 5; i < 8; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){0, -speed});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){0, -speed});
    }
}

void move_left_pnj(player_t *player, int speed)
{
    if (*player->is_in_menu_p == 0)
        for (int i = 0; i < 5; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){speed, 0});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){speed, 0});
    }
    if (*player->is_in_menu_p == 2)
        for (int i = 5; i < 8; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){speed, 0});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){speed, 0});
    }
}

void move_right_pnj(player_t *player, int speed)
{
    if (*player->is_in_menu_p == 0)
        for (int i = 0; i < 5; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){-speed, 0});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){-speed, 0});
    }
    if (*player->is_in_menu_p == 2)
        for (int i = 5; i < 8; i++) {
            sfSprite_move(player->pnj[i]->sprite_pnj, (sfVector2f){-speed, 0});
            sfSprite_move(player->pnj[i]->sprite_bubble,
            (sfVector2f){-speed, 0});
    }
}
