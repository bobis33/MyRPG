/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** mobs
*/

#ifndef MOBS_H_
    #define MOBS_H_
    #include <SFML/Graphics.h>

    typedef struct mobs_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfTexture *texture_left;
        sfTexture *texture_attack;
        sfTexture *texture_attack_left;
        sfTexture *texture_death;
        sfVector2f pos;
        sfIntRect rect;
        int hp;
        int is_alive;
        int timer_revive;

    } mobs_t;

#endif /* !MOBS_H_ */
