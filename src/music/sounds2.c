/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** sounds2
*/

#include "player.h"

void pnj_sound(player_t *player)
{
    player->pnj_sound = sfMusic_createFromFile("assets/sound_effect/talk.ogg");
    sfMusic_setLoop(player->pnj_sound, sfFalse);
    sfMusic_setVolume(player->pnj_sound, 20);
    sfMusic_play(player->pnj_sound);
}

void item_sound(player_t *player)
{
    sfMusic_play(player->item_sound);
}
