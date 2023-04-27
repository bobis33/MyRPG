/*
** EPITECH PROJECT, 2023
** utils.h
** File description:
** include for my utils
*/

#ifndef _UTILS_H_
    #define _UTILS_H_

    /* LOCAL INCLUDES */
    #include "map.h"
    #include "player.h"
    #include "window.h"
    #include "menu.h"

    /**
     * @brief Check the environment variables to see if the game can be launched
     *
     * @param env Environment variables.
     * @return int Return 0 if the arguments are correct, -1 otherwise.
     */
    int check_env(const char *env[]);

    /**
     * @brief Allocate the memory for the structures.
     *
     * @param menu Structure containing all the menu's elements.
     * @param map Structure containing all the map's elements.
     * @param player Structure containing all the player's informations.
     */
    void malloc_struct(menu_t *menu, map_t *map, player_t *player);

    /**
     * @brief Get ratio of window size.
     *
     * @param window Structure containing all the window's informations.
     */
    void get_ratio(window_t *window);

    /**
     * @brief Write a string on the standard error output.
     *
     * @param str String to write.
     * @return int Return 0 if the string is written, -1 otherwise.
     */
    int my_put_strerr(char const *str);

    /**
     * @brief Write a string on the standard output.
     *
     * @param str String to write.
     * @return int Return 0 if the string is written, -1 otherwise.
     */
    int my_put_str(char const *str);

    char *my_itoa(int nb);

#endif
