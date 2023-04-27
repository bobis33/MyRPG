/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    /* SYSTEM INCLUDES */
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    /**
     * @brief Structure of the window.
     */
    typedef struct window {
        int menu_anim_1;
        int menu_anim_2;
        int menu_anim_fade;
        int is_in_menu;
        int is_in_game;
        int is_in_game_menu;
        int is_in_settings;
        int is_in_how_play;
        int is_left;
        int rect_index;
        int attack_index;
        int walk;
        float ratio_x;
        float ratio_y;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        float seconds;
        sfSprite *sprite_cursor;
        sfTexture *texture_cursor;
        sfMusic *music;
        int music_state;
        float zoom_level;
        sfView *view;
    } window_t;

    void create_cursor(window_t *window);
    void case_cursor(window_t *window);
    void change_music(window_t *window, char *path);
    void create_music(window_t *window);

#endif /* !WINDOW_H_ */
