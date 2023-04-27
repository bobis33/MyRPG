/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** player
*/


#ifndef PLAYER_H_
    #define PLAYER_H_

    /* LOCAL INCLUDES */
    #include "pnj.h"
    #include "map.h"
    #include "window.h"
    #include "mobs.h"

    /**
     * @brief States of the player's health.
     */
    typedef enum health_state {
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX
    } health_state_t;

    typedef struct inventory_s {
        sfRectangleShape *box;
        sfVector2f pos;
        sfSprite *sprite_grimoire;
        sfTexture *texture_grimoire;
        sfSprite *sprite_shoe;
        sfTexture *texture_shoe;
        sfSprite *sprite_sword;
        sfTexture *texture_sword;
    }inventory_t;

    typedef struct boxes_s {
        inventory_t **invent;
        int *items;
    }boxes_t;

    /**
     * @brief Structure of the player.
     */
    typedef struct player {
        sfSprite *sprite_player;
        sfTexture **texture_idle;
        sfTexture **texture_walk;
        sfTexture **texture_attack;
        sfTexture *texture_dead;
        sfTexture *texture_health;
        sfSprite *sprite_health;
        sfTexture *texture_exp;
        sfSprite *sprite_exp;
        sfText *text_exp;
        sfFont *font_exp;
        sfIntRect rect;
        int already_talk;
        sfMusic *music_exp;
        int lvl_exp;
        health_state_t state;
        pnj_t **pnj;
        mobs_t **mobs;
        sfIntRect rect_mobs;
        boxes_t *boxes;
        int is_attacking;
        int has_attacked;
        int nb_pnj;
        int *is_in_menu_p;
        int is_dead;
        int respawn_done;
        int quest_advencement;
        sfMusic *walk_sound;
        sfMusic *attack_sound;
        sfMusic *blob_sound;
        sfMusic *pnj_sound;
        sfMusic *item_sound;
        sfSprite *S_strenght;
        sfTexture *T_strenght;
        sfSprite *S_add_strenght;
        sfTexture *T_add_strenght;
        int strenght;
        sfText *text_force;
        sfSprite *sprite_force;
        sfTexture *texture_force;
        int force;
        int max_hp_mob;
    } player_t;

    /**
     * @brief Create a player object.
     *
     * @param texture Texture of the player.
     * @param sprite Sprite of the player.
     */
    void create_player(sfTexture *texture, sfSprite **sprite);

    void create_pnj(player_t *player);
    void create_talk(sfTexture **texture, sfSprite **sprite);

    /**
     * @brief Create the health bar.
     *
     * @param player Structure of the player.
     */
    void create_health_bar(player_t *player);

    /**
     * @brief Move the player up.
     *
     * @param count Count of the player's movement.
     * @param walk Speed of the player's movement.
     * @param player Structure of the player.
     * @param map Sprites of the map.
     */
    void move_up(int count,
                int *walk,
                player_t *player,
                sfSprite **map);

    /**
     * @brief Move the player down.
     *
     * @param count Count of the player's movement.
     * @param walk Speed of the player's movement.
     * @param player Structure of the player.
     * @param map Sprites of the map.
     */
    void move_down(int count, int *walk, player_t *player, sfSprite **map);

    /**
     * @brief Move the player right.
     *
     * @param count Count of the player's movement.
     * @param walk Speed of the player's movement.
     * @param player Structure of the player.
     * @param map Sprites of the map.
     */
    void move_right(int count, int *walk, player_t *player, sfSprite **map);

    /**
     * @brief Move the player left.
     *
     * @param count Count of the player's movement.
     * @param walk Speed of the player's movement.
     * @param player Structure of the player.
     * @param map Sprites of the map.
     */
    void move_left(int count, int *walk, player_t *player, sfSprite **map);

    /**
     * @brief Check if the player is moving.
     *
     * @param player Structure of the player.
     * @param map Sprites of the map.
     * @param window Structure of the window.
     */
    void is_player_moving(player_t *player, map_t *map, window_t *window);

    /**
     * @brief Check if the player is idling.
     *
     * @param walk Speed of the player's movement.
     * @param rect_index Index of the player's sprite.
     * @param player Structure of the player.
     */
    void player_idle(int *walk, int *rect_index, player_t *player);

    /**
     * @brief ??????????????????
     *
     * @param player Structure of the player.
     * @param window Structure of the window.
     */
    void player_array(player_t *player);

    /**
     * @brief Check if the player can move.
     *
     * @param pos_origin Position of the player.
     * @param image Image of the map.
     * @param direction Direction of the player.
     * @return int 1 if the player can move, 0 if not.
     */
    int is_moveable(sfVector2f pos_origin, sfImage *image, int direction);

    void is_pnj_bubble(player_t *player);
    void is_pnj_talk(player_t *player, window_t *window);
    void draw_bubble(player_t *player, window_t *window);
    void draw_pnj(player_t *player, window_t *window);
    void game_inventory(player_t *player);
    void game_inventory_draw(window_t *window, player_t *player);
    void create_experience(sfTexture **texture, sfSprite **sprite);
    void create_text_exp(sfText **text, sfFont **font);
    void check_return_in_map(map_t *map, window_t *window);
    void check_change_map(map_t *map, window_t *window);
    void is_player_moving_epi(player_t *player, map_t *map, window_t *window);
    void inventory_slot1(inventory_t *invent);
    void inventory_slot2(inventory_t *invent);
    void inventory_slot3(inventory_t *invent);
    void create_music_exp(player_t *player);
    void create_zoom(window_t *window);
    void check_attack(player_t *player);
    void pos_attack_1(player_t *player);
    void pos_attack_2(player_t *player);
    void pos_attack_3(player_t *player);
    void pos_attack_4(player_t *player);
    void create_mobs(player_t *player);
    void draw_mobs(window_t *window, player_t *player);
    void check_quest_advencement(player_t *player);
    void forpnj(player_t *player, int i, char *path);
    void forbubble(player_t *player, int i);
    int is_in_range(player_t *player, int i);
    void check_mob_attack(player_t *player);
    void check_mob_respawn(player_t *player);
    void check_mob_is_hit(player_t *player);
    void check_stop_mob_attack(player_t *player);
    void move_up_pnj(player_t *player, int i);
    void move_down_pnj(player_t *player, int i);
    void move_left_pnj(player_t *player, int i);
    void move_right_pnj(player_t *player, int i);
    void set_text(player_t *player, int i);
    void draw_bubble_map2(player_t *player, window_t *window, int i);
    void draw_bubble_map1(player_t *player, window_t *window, int i);
    int replace_map(map_t *map, player_t *player);
    void create_sounds(player_t *player);
    void blob_sound(player_t *player);
    void walk_on(player_t *player);
    void walk_off(player_t *player);
    void attack_sound(player_t *player);
    void pnj_sound(player_t *player);
    void item_sound(player_t *player);
    void text_with_sword(player_t *player);
    void text_with_grimoire(player_t *player);
    char *get_all_text_in_file (const char *file_name);
    void create_up_force(player_t *player);
    void witch_pnj_has_quest(player_t *player);
    void check_update_force(player_t *player, window_t *window);
    void create_text_force(sfText **text, sfFont **font);
    void draw_force(window_t *window, player_t *player);

#endif /* !PLAYER_H_ */
