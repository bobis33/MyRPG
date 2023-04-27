/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** pnj
*/

#ifndef PNJ_H_
    #define PNJ_H_

    /* SYSTEM INCLUDES */
    #include <SFML/Graphics.h>

    /**
     * @brief Structure of the pnj.
     */
    typedef struct pnj {
        sfTexture **texture_idle;
        sfSprite *sprite_pnj;
        sfTexture **texture_bubble;
        sfSprite *sprite_bubble;
        sfIntRect rect;
        int has_quest;
        char* text_quest;
        char* text_no_quest;
        int is_bubble;
        int is_talk;
        int already_talk;
    } pnj_t;

#endif /* !PNJ_H_ */
