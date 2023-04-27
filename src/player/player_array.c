/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** tab_player
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "player.h"

static void create_texture(sfTexture **texture, char const *path)
{
    *texture = sfTexture_createFromFile(path, NULL);
}

void player_array(player_t *player)
{
    create_texture(&player->texture_idle[0], "assets/player/idle_front.png");
    create_texture(&player->texture_idle[1], "assets/player/idle_back.png");
    create_texture(&player->texture_idle[2], "assets/player/idle_left.png");
    create_texture(&player->texture_idle[3], "assets/player/idle_right.png");
    create_texture(&player->texture_walk[0], "assets/player/walk_back.png");
    create_texture(&player->texture_walk[1], "assets/player/walk_front.png");
    create_texture(&player->texture_walk[2], "assets/player/walk_right.png");
    create_texture(&player->texture_walk[3], "assets/player/walk_left.png");
    create_texture(&player->texture_attack[0],
    "assets/player/attack_front.png");
    create_texture(&player->texture_attack[1], "assets/player/attack_back.png");
    create_texture(&player->texture_attack[2], "assets/player/attack_left.png");
    create_texture(&player->texture_attack[3],
    "assets/player/attack_right.png");
    create_texture(&player->texture_dead, "assets/player/dead.png");
}
