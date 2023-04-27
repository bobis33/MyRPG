/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** quest_advencement
*/

#include "window.h"
#include "player.h"

void change_bubble_text(player_t *player, int i)
{
    if (player->pnj[i]->has_quest == 0)
        if (sfSprite_getTexture(player->pnj[i]->sprite_bubble) !=
            player->pnj[i]->texture_bubble[0])
            sfSprite_setTexture(player->pnj[i]->sprite_bubble,
                player->pnj[i]->texture_bubble[0], sfTrue);
    if (player->pnj[i]->has_quest == 1)
        if (sfSprite_getTexture(player->pnj[i]->sprite_bubble) !=
            player->pnj[i]->texture_bubble[1])
            sfSprite_setTexture(player->pnj[i]->sprite_bubble,
                player->pnj[i]->texture_bubble[1], sfTrue);

}

void check_quest_1(player_t *player)
{
    if (player->quest_advencement == 1) {
        if (player->pnj[1]->already_talk == 1) {
            player->boxes->items[0] = 1;
            text_with_sword(player);
            player->pnj[5]->already_talk = 0;
            item_sound(player);
        }
        if (player->pnj[1]->already_talk == 1 && player->pnj[5]->is_talk == 1) {
            player->quest_advencement = 2;
            player->pnj[4]->already_talk = 0;
        }
    }
}

void check_pnj_4(player_t *player)
{
    if (player->pnj[4]->already_talk == 1) {
        player->boxes->items[1] = 1;
        if (player->boxes->items[1] == 1)
            text_with_grimoire(player);
        player->pnj[5]->already_talk = 0;
        item_sound(player);
        player->quest_advencement = 3;
        if (player->quest_advencement == 3 &&
            player->pnj[5]->already_talk == 1) {
            player->boxes->items[2] = 1;
        }
    }
}

void check_quest_2(player_t *player)
{
    if (player->quest_advencement == 2) {
        check_pnj_4(player);
    }
}

void check_quest_advencement(player_t *player)
{
    if (player->quest_advencement == 0) {
        if (player->pnj[5]->already_talk == 1)
            player->quest_advencement = 1;
    }
    check_quest_1(player);
    check_quest_2(player);
    if (player->quest_advencement == 3 && player->pnj[5]->already_talk == 1) {
        player->quest_advencement = 4;
    }
    witch_pnj_has_quest(player);
    for (int i = 0; i < 8; i++)
        change_bubble_text(player, i);
}
