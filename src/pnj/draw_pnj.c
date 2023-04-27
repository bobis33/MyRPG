/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** draw_pnj
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "window.h"
#include "player.h"
#include "menu.h"

void draw_pnj(player_t *player, window_t *window)
{
    if (window->is_in_menu == 2) {
        for (int i = 5; i < 8; i++) {
            sfRenderWindow_drawSprite(window->window,
                player->pnj[i]->sprite_pnj, NULL);
        }
    }
    if (window->is_in_menu == 0) {
        for (int i = 0; i < 5; i++) {
            sfRenderWindow_drawSprite(window->window,
                player->pnj[i]->sprite_pnj, NULL);
        }
    }
}

void draw_bubble(player_t *player, window_t *window)
{
    if (window->is_in_menu == 2) {
        for (int i = 5; i < 8; i++)
            draw_bubble_map2(player, window, i);
    }
    if (window->is_in_menu == 0) {
        for (int i = 0; i < 5; i++) {
            draw_bubble_map1(player, window, i);
        }
    }
}

void draw_text(window_t *window, player_t *player, int i)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText *text = sfText_create();
    if (player->pnj[i]->has_quest == 0)
        sfText_setString(text, player->pnj[i]->text_no_quest);
    else if (player->pnj[i]->has_quest == 1)
        sfText_setString(text, player->pnj[i]->text_quest);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setOutlineThickness(text, 2);
    sfText_setPosition(text, (sfVector2f){430, 900});
    sfRenderWindow_drawText(window->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void draw_talk(menu_t *menu, player_t *player, window_t *window)
{
    for (int i = 0; i < 8; i++) {
        if (player->pnj[i]->is_talk == 1) {
            sfRenderWindow_drawSprite(window->window, menu->sprite_talk, NULL);
            draw_text(window, player, i);
        }
    }
}
