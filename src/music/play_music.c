/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** play_music
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "window.h"
#include "player.h"

void create_music(window_t *window)
{
    window->music = sfMusic_createFromFile("assets/music/menu.ogg");
    sfMusic_setLoop(window->music, sfTrue);
    sfMusic_setVolume(window->music, 10);
    sfMusic_play(window->music);
}

void change_music(window_t *window, char *path)
{
    sfMusic_stop(window->music);
    sfMusic_destroy(window->music);
    window->music = sfMusic_createFromFile(path);
    sfMusic_setLoop(window->music, sfTrue);
    sfMusic_setVolume(window->music, 10);
    sfMusic_play(window->music);
}

void create_music_exp(player_t *player)
{
    player->music_exp = sfMusic_createFromFile("assets/music/level_up.ogg");
    sfMusic_setVolume(player->music_exp, 20);
}
