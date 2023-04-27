/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** utils
*/


#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include "player.h"


// direction 1 == UP
// direction 2 == DOWN
// direction 3 == left
// direction 4 == right


static int check_direction(sfVector2f pos_1, sfVector2f pos_2,
int direction, sfImage *image)
{
    if (direction == 1) {
        pos_1.y -= -10; pos_1.x += -5;
        pos_2.y -= -10; pos_2.x += 5;
    } if (direction == 2) {
        pos_1.y += 18; pos_1.x += -5;
        pos_2.y += 18; pos_2.x += 5;
    } if (direction == 3) {
        pos_1.y -= -11; pos_1.x += -7;
        pos_2.y += 17; pos_2.x += -7;
    } if (direction == 4) {
        pos_1.y -= -11; pos_1.x += 7;
        pos_2.y += 17; pos_2.x += 7;
    }
    sfColor color_1 = sfImage_getPixel(image, pos_1.x, pos_1.y);
    sfColor color_2 = sfImage_getPixel(image, pos_2.x, pos_2.y);
    if (color_1.a == 255 && color_2.a == 255)
        return 1;
    return 0;
}

int is_moveable(sfVector2f pos_origin, sfImage *image, int direction)
{
    pos_origin.x = ((pos_origin.x * -1) + 960) / 6;
    pos_origin.y = ((pos_origin.y * -1) + 540) / 6;
    sfVector2f pos_1 = pos_origin;
    sfVector2f pos_2 = pos_origin;
    if (check_direction(pos_1, pos_2, direction, image) == 1)
        return 1;
    return 0;
}
