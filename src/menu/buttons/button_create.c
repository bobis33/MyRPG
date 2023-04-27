/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** button_create
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>

/* LOCAL INCLUDES */
#include "menu.h"
#include "button.h"


static void create_button_menu(sfTexture *texture, sfSprite **sprite,
sfVector2f pos)
{
    sfVector2f scale = {1.5, 1.5};
    sfIntRect pos_rect = {0, 49, 190, 49};

    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
    sfSprite_setTextureRect(*sprite, pos_rect);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

static void create_button_quit_settings(sfTexture *texture,
sfSprite **sprite, sfVector2f pos)
{
    sfVector2f scale = {1.5, 1.5};
    sfIntRect pos_rect = {185, 433, 37, 36};
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
    sfSprite_setTextureRect(*sprite, pos_rect);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

void ini_button_menu(menu_t *menu)
{
    menu->button->texture_button[0] =
    sfTexture_createFromFile("assets/menu/button/greySheet_play.png", NULL);
    create_button_menu(menu->button->texture_button[0],
    &menu->button->sprite_button[0], (sfVector2f){220, 450});
    menu->button->texture_button[3] =
    sfTexture_createFromFile("assets/menu/button/greySheet_HowToP.png", NULL);
    create_button_menu(menu->button->texture_button[3],
    &menu->button->sprite_button[3], (sfVector2f){620, 450});
    menu->button->texture_button[1] =
    sfTexture_createFromFile("assets/menu/button/greySheet_settings.png", NULL);
    create_button_menu(menu->button->texture_button[1],
    &menu->button->sprite_button[1], (sfVector2f){1020, 450});
    menu->button->texture_button[2] =
    sfTexture_createFromFile("assets/menu/button/greySheet_exit.png", NULL);
    create_button_menu(menu->button->texture_button[2],
    &menu->button->sprite_button[2], (sfVector2f){1420, 450});
    create_button_quit_settings(menu->button->texture_button[0],
    &menu->button->sprite_button[4], (sfVector2f){1855, 15});
}
