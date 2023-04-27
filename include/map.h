/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    /* SYSTEM INCLUDES */
    #include <SFML/Graphics.h>

    /**
     * @brief Structure of the map.
     */
    typedef struct map{
        sfTexture **texture_map;
        sfSprite **sprite_map;
        sfImage *image;
        sfTexture **texture_epi;
        sfSprite **sprite_epi;
        sfImage *image_epi;
    } map_t;

    /**
     * @brief Create the world.
     *
     * @param map Structure of the map.
     */
    void create_world(map_t *map);

#endif /* !MAP_H_ */
