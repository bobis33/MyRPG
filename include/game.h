/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "map.h"
    #include "menu.h"
    #include "player.h"

    /**
     * @brief Initialize the game.
     *
     * @param window Structure containing all the window's elements.
     * @param menu Structure containing all the menu's elements.
     * @param map Structure containing all the map's elements.
     * @param player Structure containing all the player's informations.
     */
    void game_init(window_t *window,
                    menu_t *menu,
                    map_t *map,
                    player_t *player);

    /**
     * @brief Main loop of the game.
     *
     * @param window Structure containing all the window's elements.
     * @param menu Structure containing all the menu's elements.
     * @param map Structure containing all the map's elements.
     * @param player Structure containing all the player's informations.
     */
    void game_loop(window_t *window,
                    menu_t *menu,
                    map_t *map,
                    player_t *player);

    /**
     * @brief Create the first layer of the game.
     *
     * @param window Structure containing all the window's elements.
     * @param menu Structure containing all the menu's elements.
     * @param map Structure containing all the map's elements.
     * @param player Structure containing all the player's informations.
     */
    void create_game_layer_1(window_t *window,
                                menu_t *menu,
                                map_t *map,
                                player_t *player);

    /**
     * @brief Create the second layer of the game.
     *
     * @param window Structure containing all the window's elements.
     * @param menu Structure containing all the menu's elements.
     * @param map Structure containing all the map's elements.
     * @param player Structure containing all the player's informations.
     */
    void create_game_layer_2(window_t *window,
                                menu_t *menu,
                                map_t *map,
                                player_t *player);

    void scroll_case(window_t *window);
    void ini_struct_window(window_t *window);
    void ini_struct_player(window_t *window, player_t *player);
    void create_game(window_t *window, menu_t *menu,
    map_t *map, player_t *player);
    void create_text_game_menu(menu_t *menu);
    void create_illustration_game_menu(menu_t *menu);
    void game_menu(window_t *window, menu_t *menu, player_t *player);
    void case_hud(window_t *window, player_t *player);
    void health_bar_case(player_t *player);

#endif /* !GAME_H_ */
