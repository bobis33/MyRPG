/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** which_pnj_has_quest
*/

#include "player.h"

void witch_pnj_has_quest(player_t *player)
{
    if (player->quest_advencement == 0) {
        if (player->pnj[0]->has_quest == 0)
            player->pnj[0]->has_quest = 1;
        if (player->pnj[1]->has_quest == 1)
            player->pnj[1]->has_quest = 0;
    }
    if (player->quest_advencement == 1) {
        if (player->pnj[0]->has_quest == 1)
            player->pnj[0]->has_quest = 0;
        if (player->pnj[1]->has_quest == 1)
            player->pnj[1]->has_quest = 0;
    }
    if (player->quest_advencement == 2) {
        if (player->pnj[1]->has_quest == 1)
            player->pnj[1]->has_quest = 0;
        if (player->pnj[4]->has_quest == 0)
            player->pnj[4]->has_quest = 1;
    }
}
