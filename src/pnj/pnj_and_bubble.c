/*
** EPITECH PROJECT, 2023
** pnj_and_bubble.c
** File description:
** pnj_and_bubble
*/

#include <stdlib.h>
#include "player.h"

void forpnj(player_t *player, int i, char *path)
{
    player->pnj[i]->texture_idle = malloc(sizeof(sfTexture *) * 4);
    player->pnj[i]->texture_idle[0] =
        sfTexture_createFromFile(path, NULL);
    player->pnj[i]->sprite_pnj = sfSprite_create();
    sfSprite_setTexture(player->pnj[i]->sprite_pnj,
        player->pnj[i]->texture_idle[0], sfTrue);
    sfSprite_setScale(player->pnj[i]->sprite_pnj, (sfVector2f){5, 5});
}

void forbubble(player_t *player, int i)
{
    player->pnj[i]->texture_bubble = malloc(sizeof(sfTexture *) * 2);
    player->pnj[i]->texture_bubble[0] =
        sfTexture_createFromFile("assets/talk/bubble_talk.png", NULL);
    player->pnj[i]->texture_bubble[1] =
        sfTexture_createFromFile("assets/talk/bubble_quest.png", NULL);
    player->pnj[i]->sprite_bubble = sfSprite_create();
    sfSprite_setTexture(player->pnj[i]->sprite_bubble,
        player->pnj[i]->texture_bubble[0], sfTrue);
    sfSprite_setScale(player->pnj[i]->sprite_bubble, (sfVector2f){5, 5});
}
