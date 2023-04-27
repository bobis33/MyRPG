/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game_experience
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>

/* LOCAL INCLUDES */
#include "player.h"
#include "menu.h"
#include "utils.h"


void create_experience(sfTexture **texture, sfSprite **sprite)
{
    sfVector2f pos = {1800, 45};
    sfVector2f scale = {0.09, 0.09};

    *texture = sfTexture_createFromFile("assets/player/experience.png", NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

void create_text_exp(sfText **text, sfFont **font)
{
    sfVector2f pos_text = {1870, 50};

    *text = sfText_create();
    *font = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText_setFont(*text, *font);
    sfText_setString(*text, "1");
    sfText_setCharacterSize(*text, 30);
    sfText_setPosition(*text, pos_text);
}

void create_text_force(sfText **text, sfFont **font)
{
    sfVector2f pos_text = {950, 376};

    *text = sfText_create();
    *font = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText_setFont(*text, *font);
    sfText_setString(*text, "0");
    sfText_setCharacterSize(*text, 30);
    sfText_setPosition(*text, pos_text);
}
