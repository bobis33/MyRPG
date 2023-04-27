/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_menu
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>

/* LOCAL INCLUDES */
#include "window.h"
#include "menu.h"


void create_illustration_game_menu(menu_t *menu)
{
    sfVector2f scale = {20, 20};
    sfIntRect pos_rect = {100, 10, 50, 100};
    menu->sprite_player = sfSprite_create();
    menu->texture_player
    = sfTexture_createFromFile("assets/player/idle_front.png", NULL);
    sfSprite_setTexture(menu->sprite_player, menu->texture_player, sfTrue);
    sfSprite_setTextureRect(menu->sprite_player, pos_rect);
    sfSprite_setPosition(menu->sprite_player, (sfVector2f){0, 0});
    sfSprite_setScale(menu->sprite_player, scale);
}

void create_text_game_menu(menu_t *menu)
{
    sfVector2f pos_text = {875, 20};

    menu->text_game_menu = sfText_create();
    sfText_setFont(menu->text_game_menu, menu->font_settings);
    sfText_setString(menu->text_game_menu, "MENU");
    sfText_setCharacterSize(menu->text_game_menu, 75);
    sfText_setPosition(menu->text_game_menu, pos_text);
}

static void button_case_game_menu(window_t *window, menu_t *menu,
sfVector2i pos_mouse)
{
    sfIntRect pos_rect_third = {0, 143, 190, 45};
    sfIntRect pos_rect_origin = {0, 49, 190, 49};
    if (pos_mouse.x > 1857 && pos_mouse.x < 1908
    && pos_mouse.y > 16 && pos_mouse.y < 65
    && sfMouse_isButtonPressed(sfMouseLeft) == true)
        window->is_in_game_menu = 0;
    if (pos_mouse.x > 1598 && pos_mouse.x < 1882
    && pos_mouse.y > 920 && pos_mouse.y < 987
    && window->is_in_game == 1) {
        sfSprite_setTextureRect(menu->button->sprite_button[1],
        pos_rect_third);
        if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
            window->is_in_game_menu = 0;
            window->is_in_settings = 1;
        }
    } else if (window->is_in_game == 1) {
        sfSprite_setTextureRect(menu->button->sprite_button[1],
        pos_rect_origin);
    }
}

void draw_stat(window_t *window, player_t *player, menu_t *menu)
{
    sfRenderWindow_drawSprite(window->window, menu->sprite_player, NULL);
    sfRenderWindow_drawText(window->window, menu->health, NULL);
    sfRenderWindow_drawText(window->window, menu->force, NULL);
    sfRenderWindow_drawText(window->window, menu->speed, NULL);
    sfRenderWindow_drawText(window->window, menu->experience, NULL);
    sfText_setPosition(player->text_exp, (sfVector2f){950, 525});
    sfRenderWindow_drawText(window->window, player->text_exp, NULL);
}

void game_menu(window_t *window, menu_t *menu, player_t *player)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window->window);
    if (window->is_in_game_menu == 1) {
        sfSprite_setPosition(menu->button->sprite_button[1],
        (sfVector2f){1600, 920});
        sfRenderWindow_drawRectangleShape(window->window,
        menu->rect_settings, NULL);
        sfRenderWindow_drawSprite(window->window,
        menu->button->sprite_button[1], NULL);
        sfRenderWindow_drawText(window->window, menu->text_game_menu, NULL);
        sfRenderWindow_drawSprite(window->window,
        menu->button->sprite_button[4], NULL);
        button_case_game_menu(window, menu, pos_mouse);
        draw_stat(window, player, menu);
        sfRenderWindow_drawText(window->window, player->text_force, NULL);
        draw_force(window, player);
    }
    sfText_setPosition(player->text_exp, (sfVector2f){1870, 50});
}
