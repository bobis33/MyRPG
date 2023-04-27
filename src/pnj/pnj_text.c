/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** pnj_text
*/

#include "player.h"
#include "window.h"

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_all_text_in_file (const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    struct stat st;
    stat(file_name, &st);
    char *text = malloc(sizeof(char) * (st.st_size + 1));

    read(fileno(file), text, st.st_size);
    
    text[st.st_size] = '\0';
    fclose(file);
    return text;
}

void set_text2(player_t *player, int i)
{
    if (i == 4) {
        player->pnj[i]->text_no_quest =
        get_all_text_in_file("texts/pnj4_no_quest.txt");
        player->pnj[i]->text_quest =
        get_all_text_in_file("texts/pnj4_quest.txt");
    }
    if (i == 5) {
        player->pnj[i]->text_quest =
        get_all_text_in_file("texts/pnj5_quest.txt");
        player->pnj[i]->text_no_quest =
        get_all_text_in_file("texts/pnj5_no_quest.txt");
    }
    if (i == 6 || i == 7) {
        player->pnj[i]->text_no_quest =
        get_all_text_in_file("texts/pnj6_7_no_quest.txt");
    }
}

void set_text(player_t *player, int i)
{
    if (i == 0) {
        player->pnj[i]->text_quest =
        get_all_text_in_file("texts/pnj0_quest.txt");
        player->pnj[i]->text_no_quest =
        get_all_text_in_file("texts/pnj0_no_quest.txt");
    } if (i == 1) {
        player->pnj[i]->text_quest =
        get_all_text_in_file("texts/pnj1_quest.txt");
        player->pnj[i]->text_no_quest =
        get_all_text_in_file("texts/pnj1_no_quest.txt");
    } if (i == 2) {
        player->pnj[i]->text_no_quest =
        get_all_text_in_file("texts/pnj2_no_quest.txt");
    } if (i == 3) {
        player->pnj[i]->text_no_quest =
        get_all_text_in_file("texts/pnj3_4_no_quest.txt");
    }
    set_text2(player, i);
}
