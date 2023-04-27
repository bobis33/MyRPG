/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_strenght
*/

#include "player.h"

void create_up_force(player_t *player)
{
    player->texture_force = sfTexture_createFromFile("assets/force.png", NULL);
    player->sprite_force = sfSprite_create();
    sfSprite_setTexture(player->sprite_force, player->texture_force, sfTrue);
    sfSprite_setPosition(player->sprite_force, (sfVector2f){0, 0});
    sfSprite_setScale(player->sprite_force, (sfVector2f){1, 1});
    player->force = 0;
    player->max_hp_mob = 4;
}

int check_click_force(window_t *window)
{
    float pos_x = sfMouse_getPositionRenderWindow(window->window).x;
    float pos_y = sfMouse_getPositionRenderWindow(window->window).y;
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos_x >= 1155 && pos_x <= 1223
        && pos_y >= 357 && pos_y <= 423) {
        return 1;
    }
    return 0;
}

void draw_force(window_t *window, player_t *player)
{
    if (player->force < 3 && player->lvl_exp >= 10)
        sfRenderWindow_drawSprite(window->window, player->sprite_force, NULL);
}

void change_max_hp_mob(player_t *player)
{
    for (int i = 0; i < 10; i++) {
        player->mobs[i]->hp = player->max_hp_mob;
    }
}

void check_update_force(player_t *player, window_t *window)
{
    if (window->is_in_game_menu == 1 && player->force < 3 &&
        player->lvl_exp >= 10) {
        if (check_click_force(window) == 1) {
            player->force += 1;
            player->lvl_exp -= 10;
            player->max_hp_mob --;
            change_max_hp_mob(player);
            window->is_in_game_menu = 0;
        }
    }
}
