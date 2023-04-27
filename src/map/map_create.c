/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** create_map
*/

/* SYSTEM INCLUDES */
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

/* LOCAL INCLUDES */
#include "map.h"

static void create_map(sfTexture **texture, sfSprite **sprite, const char *path)
{
    sfVector2f pos = {-4400, -7292};
    sfVector2f scale = {6, 6};

    *texture = sfTexture_createFromFile(path, NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

static void create_house_epi(sfTexture **texture, sfSprite **sprite,
const char *path)
{
    sfVector2f pos = {-618, -1058};
    sfVector2f scale = {6, 6};

    *texture = sfTexture_createFromFile(path, NULL);
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, pos);
    sfSprite_setScale(*sprite, scale);
}

void create_world(map_t *map)
{
    create_map(&map->texture_map[0], &map->sprite_map[0],
    "assets/maps/map.png");
    create_map(&map->texture_map[1], &map->sprite_map[1],
    "assets/maps/map_layer.png");
    create_map(&map->texture_map[2], &map->sprite_map[2],
    "assets/maps/map_collision.png");
    create_house_epi(&map->texture_epi[0], &map->sprite_epi[0],
    "assets/maps/epi.png");
    create_house_epi(&map->texture_epi[1], &map->sprite_epi[1],
    "assets/maps/epi_layer.png");
    create_house_epi(&map->texture_epi[2], &map->sprite_epi[2],
    "assets/maps/epi_collision.png");
    map->image = sfTexture_copyToImage(map->texture_map[2]);
    map->image_epi = sfTexture_copyToImage(map->texture_epi[2]);

}
