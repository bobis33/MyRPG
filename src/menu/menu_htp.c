/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu_htp
*/


/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>

/* LOCAL INCLUDES */
#include "window.h"
#include "menu.h"


static void create_text(sfText **text, sfFont **font)
{
    sfVector2f pos_text = {730, 20};

    *text = sfText_create();
    *font = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText_setFont(*text, *font);
    sfText_setString(*text, "HOW TO PLAY");
    sfText_setCharacterSize(*text, 75);
    sfText_setPosition(*text, pos_text);
}

static void create_text_tuto(sfText **text, sfFont **font)
{
    sfVector2f pos_text = {300, 150};

    *text = sfText_create();
    *font = sfFont_createFromFile("assets/fonts/font_pixel.ttf");
    sfText_setFont(*text, *font);
    sfText_setString(*text, "Vous etes un jeune etudiant en magie et arrivez "
    "tout juste dans la ville de Goldenleaf\n\n(ville ou se situe votre "
    "academie : CodSpell).\n\n\n\nVotre objectif est de retrouver la 'MSC'.\n\n"
    "Vous decouvrirez ce qu'est la MSC au fur et a mesure que vous avancerez "
    "dans le jeu.\n\n\n\nPour vous deplacer, rien de plus simple ! Utiliser les"
    " touches directionnelles de votre clavier.\n\nVous pourrez interagir avec "
    "les personnages (PNJ ou NPC) du jeu avec la touche E.\n\nPressez cette "
    "touche lorsque vous etes proche d'un PNJ pour interagir avec.\n\nPour "
    "attaquer, utilisez la touche espace de votre clavier.\n\n");
    sfText_setCharacterSize(*text, 25);
    sfText_setPosition(*text, pos_text);
}

void create_keyboard_sprite(sfTexture **texture, sfSprite **sprite)
{
    sfVector2f pos = {300, 750};
    sfVector2f scale = {0.5, 0.5};

    *texture = sfTexture_createFromFile("assets/menu/how_to_play/keyboard.png",
    NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

void create_htp_fade(menu_t *menu)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {1920, 1080};
    sfColor color = {0, 0, 0, 220};

    menu->rect_htp = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->rect_htp, size);
    sfRectangleShape_setPosition(menu->rect_htp, pos);
    sfRectangleShape_setFillColor(menu->rect_htp, color);
    create_text(&menu->text_htp, &menu->font_htp);
    create_text_tuto(&menu->text_htp_2, &menu->font_htp);
    create_keyboard_sprite(&menu->texture_keyboard, &menu->sprite_keyboard);
}

void menu_how_play(window_t *window, menu_t *menu)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window->window);
    if (window->is_in_how_play == 1) {
        sfRenderWindow_drawRectangleShape(window->window,
        menu->rect_htp, NULL);
        sfRenderWindow_drawText(window->window, menu->text_htp, NULL);
        sfRenderWindow_drawText(window->window, menu->text_htp_2, NULL);
        sfRenderWindow_drawSprite(window->window,
        menu->button->sprite_button[4], NULL);
        sfRenderWindow_drawSprite(window->window, menu->sprite_keyboard, NULL);
        if (pos_mouse.x > 1857 && pos_mouse.x < 1908
        && pos_mouse.y > 16 && pos_mouse.y < 65
        && sfMouse_isButtonPressed(sfMouseLeft) == true)
            window->is_in_how_play = 0;
    }
}
