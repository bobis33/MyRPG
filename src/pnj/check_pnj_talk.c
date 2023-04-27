/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** check_pnj_talk
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "player.h"

void check_pnj_talk(player_t *player, int i)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        pnj_sound(player);
        player->pnj[i]->is_talk = 1;
        player->pnj[i]->already_talk = 1;
        if (player->already_talk == 0) {
            create_music_exp(player);
            sfMusic_play(player->music_exp);
            player->already_talk = 1;
            player->lvl_exp += 1;
        }
    }
}

void is_talk_map1(player_t *player)
{
    for (int i = 5; i < 8; i++) {
        if (player->pnj[i]->is_bubble == 1 && player->pnj[i]->is_talk == 0)
            check_pnj_talk(player, i);
    }
}

void is_talk_map2(player_t *player)
{
    for (int i = 0; i < 5; i++) {
        if (player->pnj[i]->is_bubble == 1 && player->pnj[i]->is_talk == 0)
            check_pnj_talk(player, i);
    }
}

void is_pnj_talk(player_t *player, window_t *window)
{
    if (window->is_in_menu == 0)
        is_talk_map2(player);
    if (window->is_in_menu == 2)
        is_talk_map1(player);
}
