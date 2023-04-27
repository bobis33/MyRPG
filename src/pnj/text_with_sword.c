/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** text_with_sword
*/

#include "player.h"

void text_with_grimoire(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest3.txt");
}

void text_with_sword(player_t *player)
{
    player->pnj[5]->text_quest = get_all_text_in_file("texts/pnj5_quest2.txt");
}
