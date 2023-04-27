/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** check_change_map
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include "map.h"
#include "player.h"

int check_color(sfImage *image, sfVector2f pos)
{
    pos.x = ((pos.x * -1) + 960) / 6;
    pos.y = ((pos.y * -1) + 540) / 6;
    sfColor color = sfImage_getPixel(image, pos.x, pos.y + 20);
    if (color.g == 255 && color.b == 0 && color.r == 0)
        return 1;
    return 0;
}

void check_change_map(map_t *map, window_t *window)
{
    int color_ground = check_color(map->image, sfSprite_getPosition
        (map->sprite_map[2]));
    if (color_ground == 1) {
        window->is_in_menu = 2;
        for (int i = 0; i < 3; i++) {
            sfSprite_setPosition(map->sprite_map[i], (sfVector2f)
                {sfSprite_getPosition(map->sprite_map[i]).x,
                sfSprite_getPosition(map->sprite_map[i]).y - 20});
        }
    }
}

void check_return_in_map(map_t *map, window_t *window)
{
    int color_ground = check_color(map->image_epi, sfSprite_getPosition
        (map->sprite_epi[2]));
    if (color_ground == 1) {
        window->is_in_menu = 0;
        for (int i = 0; i < 3; i++) {
            sfSprite_setPosition(map->sprite_epi[i], (sfVector2f)
            {sfSprite_getPosition(map->sprite_epi[i]).x,
            sfSprite_getPosition(map->sprite_epi[i]).y + 20});
        }
    }
}
