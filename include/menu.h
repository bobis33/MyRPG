/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    /* SYSTEM INCLUDES */
    #include <SFML/Graphics.h>

    /* LOCAL INCLUDES */
    #include "player.h"
    #include "button.h"

    /**
     * @brief Structure of the menu.
     */
    typedef struct menu {
        button_t *button;
        sfTexture **texture_paralax;
        sfSprite **sprite_paralax;
        sfTexture *texture_paralax_9;
        sfSprite *sprite_paralax_9;
        sfRectangleShape *fade;
        sfColor color_fade;
        sfTexture *texture_background;
        sfSprite *sprite_background;
        sfTexture *texture_title;
        sfSprite *sprite_title;
        sfTexture *texture_talk;
        sfSprite *sprite_talk;
        sfTexture *settings_texture;
        sfSprite **settings_sprite;
        sfTexture *texture_keyboard;
        sfSprite *sprite_keyboard;
        sfText *text_settings;
        sfFont *font_settings;
        sfText *text_game_menu;
        sfRectangleShape *rect_settings;
        sfText *text_htp;
        sfText *text_htp_2;
        sfFont *font_htp;
        sfText *speed;
        sfText *health;
        sfText *force;
        sfText *experience;
        sfRectangleShape *rect_htp;
        sfTexture *texture_player;
        sfSprite *sprite_player;
    } menu_t;

    /**
     * @brief Create a menu object.
     *
     * @param menu Structure of the menu.
     * @param color_fade Color of the fade.
     */
    void create_menu(menu_t *menu, sfColor color_fade);

    /**
     * @brief Draw the menu.
     *
     * @param menu Structure of the menu.
     * @param window Structure of the window.
     * @param title Structure of the title.
     */
    void draw_menu(menu_t *menu, sfRenderWindow *window, sfSprite *title);

    /**
     * @brief Do the animation of the menu.
     *
     * @param window Structure of the window.
     * @param player Structure of the player.
     * @param menu Structure of the menu.
     */
    void animation_menu_1(window_t *window, player_t *player, menu_t *menu);

    /**
     * @brief Do the animation of the menu.
     *
     * @param window Structure of the window.
     * @param player Structure of the player.
     * @param menu Structure of the menu.
     * @param map Structure of the map.
     */
    void animation_menu_2(window_t *window,
                        player_t *player,
                        menu_t *menu,
                        map_t *map);

    /**
     * @brief Do the animation of the player in the menu.
     *
     * @param window Structure of the window.
     * @param player Structure of the player.
     */
    void animation_player_menu(window_t *window, player_t *player);

    /**
     * @brief Do the animation of the paralax.
     *
     * @param menu Structure of the menu.
     */
    void move_paralax(menu_t *menu);


    void ini_button_menu(menu_t *menu);
    void button_case_menu(window_t *window, menu_t *menu);
    void create_settings_fade(menu_t *menu);
    void menu_settings(window_t *window, menu_t *menu);
    void create_htp_fade(menu_t *menu);
    void menu_how_play(window_t *window, menu_t *menu);
    void draw_talk(menu_t *menu, player_t *player, window_t *window);
    void check_death(player_t *player, window_t *window, menu_t *menu,
        map_t *map);

#endif /* !MENU_H_ */
