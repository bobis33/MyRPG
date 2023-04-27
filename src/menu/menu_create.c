/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** create_menu
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "menu.h"

static void create_fade(sfRectangleShape **rect, sfColor color_fade)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {1920, 1080};

    *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(*rect, size);
    sfRectangleShape_setPosition(*rect, pos);
    sfRectangleShape_setFillColor(*rect, color_fade);
}

static void create_title(sfTexture **texture, sfSprite **sprite)
{
    sfVector2f pos = {(1920 / 2) - (500 * 1.5), (1080 / 2) - (350 * 1.5)};
    sfVector2f scale = {1.5, 1.5};

    *texture = sfTexture_createFromFile("assets/menu/RPG_title.png", NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

static void create_paralax(sfTexture **texture, sfSprite **sprite,
const char *path)
{
    sfVector2f pos = {0, 0};
    sfVector2f scale = {6, 6};

    *texture = sfTexture_createFromFile(path, NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

static void tab_paralax(menu_t *menu)
{
    create_paralax(&menu->texture_background, &menu->sprite_background,
    "assets/menu/back_ground_menu.png");
    create_paralax(&menu->texture_paralax[0], &menu->sprite_paralax[0],
    "assets/menu/parallax/menu_1.png");
    create_paralax(&menu->texture_paralax[1], &menu->sprite_paralax[1],
    "assets/menu/parallax/menu_2.png");
    create_paralax(&menu->texture_paralax[2], &menu->sprite_paralax[2],
    "assets/menu/parallax/menu_3.png");
    create_paralax(&menu->texture_paralax[3], &menu->sprite_paralax[3],
    "assets/menu/parallax/menu_4.png");
    create_paralax(&menu->texture_paralax[4], &menu->sprite_paralax[4],
    "assets/menu/parallax/menu_5.png");
    create_paralax(&menu->texture_paralax[5], &menu->sprite_paralax[5],
    "assets/menu/parallax/menu_6.png");
    create_paralax(&menu->texture_paralax[6], &menu->sprite_paralax[6],
    "assets/menu/parallax/menu_7.png");
    create_paralax(&menu->texture_paralax[7], &menu->sprite_paralax[7],
    "assets/menu/parallax/menu_8.png");
    create_paralax(&menu->texture_paralax_9, &menu->sprite_paralax_9,
    "assets/menu/parallax/menu_9.png");
}

void create_menu(menu_t *menu, sfColor color_fade)
{
    create_title(&menu->texture_title, &menu->sprite_title);
    tab_paralax(menu);
    create_fade(&menu->fade, color_fade);
    create_talk(&menu->texture_talk, &menu->sprite_talk);
}
