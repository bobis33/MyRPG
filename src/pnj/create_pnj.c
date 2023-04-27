/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** create_pnj
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

#include <stddef.h>
#include <stdint.h>

#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* LOCAL INCLUDES */
#include "player.h"

char * change_pnj_sprite(int i)
{
    char *path = NULL;
    if (i == 0)
        path = "assets/pnj/idle_front_pnj1.png";
    if (i == 1)
        path = "assets/pnj/idle_front_pnj6.png";
    if (i == 2)
        path = "assets/pnj/idle_right_pnj2.png";
    if (i == 3)
        path = "assets/pnj/idle_front_pnj8.png";
    if (i == 4)
        path = "assets/pnj/idle_front_pnj7.png";
    if (i == 5)
        path = "assets/pnj/idle_front_pnj3.png";
    if (i == 6)
        path = "assets/pnj/idle_right_pnj4.png";
    if (i == 7)
        path = "assets/pnj/idle_left_pnj5.png";
    return path;
}

static void setpos(int i, sfVector2f pos, player_t *player)
{
    sfSprite_setPosition(player -> pnj[i]->sprite_pnj, pos);
    sfSprite_setPosition(player -> pnj[i]->sprite_bubble,
        (sfVector2f){pos.x + 110, pos.y + 23});
}

void check_setpos(int i, player_t *player)
{
    if (i == 0)
        setpos(i, (sfVector2f){710, -325}, player);
    if (i == 1)
        setpos(i, (sfVector2f){-345, -3990}, player);
    if (i == 2)
        setpos(i, (sfVector2f){-1870, -3980}, player);
    if (i == 3)
        setpos(i, (sfVector2f){10000, 10000}, player);
    if (i == 4)
        setpos(i, (sfVector2f){3950, -3600}, player);
    if (i == 5)
        setpos(i, (sfVector2f){1550, -750}, player);
    if (i == 6)
        setpos(i, (sfVector2f){750, -450}, player);
    if (i == 7)
        setpos(i, (sfVector2f){850, -450}, player);
}

void attribute_quest(player_t *player, int i)
{
    if (i == 0)
        player->pnj[i]->has_quest = 1;
    if (i == 1)
        player->pnj[i]->has_quest = 0;
    if (i == 2)
        player->pnj[i]->has_quest = 0;
    if (i == 3)
        player->pnj[i]->has_quest = 0;
    if (i == 4)
        player->pnj[i]->has_quest = 0;
    if (i == 5)
        player->pnj[i]->has_quest = 1;
    if (i > 5)
        player->pnj[i]->has_quest = 0;
}

void create_pnj(player_t *player)
{
    char *path = NULL;
    player->nb_pnj = 2;
    player->pnj = malloc(sizeof(pnj_t *) * 9);
    player->pnj[8] = NULL;
    for (int i = 0; i < 8; i++) {
        player->pnj[i] = malloc(sizeof(pnj_t));
        player->pnj[i]->already_talk = 0;
        path = change_pnj_sprite(i);
        forpnj(player, i, path);
        forbubble(player, i);
        check_setpos(i, player);
        attribute_quest(player, i);
        set_text(player, i);
    }
}
