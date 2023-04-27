/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** sounds
*/

#include "player.h"

void create_sounds(player_t *player)
{
    player->walk_sound = sfMusic_createFromFile("assets/sound_effect/walk.ogg");
    sfMusic_setLoop(player->walk_sound, sfTrue);
    sfMusic_setVolume(player->walk_sound, 0);
    sfMusic_play(player->walk_sound);
    player->item_sound = sfMusic_createFromFile("assets/sound_effect/item.ogg");
    sfMusic_setLoop(player->item_sound, sfFalse);
    sfMusic_setVolume(player->item_sound, 20);
}

void walk_on(player_t *player)
{
    sfMusic_setVolume(player->walk_sound, 20);
}

void walk_off(player_t *player)
{
    sfMusic_setVolume(player->walk_sound, 0);
}

void attack_sound(player_t *player)
{
    player->attack_sound = sfMusic_createFromFile
        ("assets/sound_effect/sword.ogg");
    sfMusic_setLoop(player->attack_sound, sfFalse);
    sfMusic_setVolume(player->attack_sound, 20);
    sfMusic_play(player->attack_sound);
}

void blob_sound(player_t *player)
{
    player->blob_sound = sfMusic_createFromFile("assets/sound_effect/blob.ogg");
    sfMusic_setLoop(player->blob_sound, sfFalse);
    sfMusic_setVolume(player->blob_sound, 20);
    sfMusic_play(player->blob_sound);
}
