##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## EPITECH Project Makefile for SOLO_STUMPER
##


ECHO 			= 	@echo

SRC_MAIN 		=	src/main.c

SRC_GAME		=	src/game/game_layer.c					\
					src/game/game.c							\
					src/game/game_inventory.c				\
					src/game/inventory_slots.c				\
					src/game/game_zoom.c					\
					src/game/cursor/cursor.c				\
					src/game/game_experience.c				\
					src/game/game_init.c					\
					src/game/game_menu.c					\
					src/game/hud/case_hud.c					\
					src/mobs/mobs.c							\
					src/mobs/mobs_attack.c					\
					src/mobs/mobs_taking_damage.c			\
					src/mobs/mobs_respawn.c					\
					src/music/play_music.c					\
					src/music/sounds.c						\
					src/music/sounds2.c						\

SRC_PLAYER		= 	src/player/player.c						\
					src/player/player_create.c				\
					src/player/player_move.c				\
					src/player/player_idle.c				\
					src/player/player_array.c				\
					src/player/player_check.c 				\
					src/player/check_attack.c				\
					src/player/check_pos_attack.c			\
					src/player/check_death.c				\
					src/player/up_force.c 					\
					src/pnj/create_pnj.c					\
					src/pnj/pnj_and_bubble.c				\
					src/pnj/create_pnj_talk.c				\
					src/pnj/check_pnj_bubble.c				\
					src/pnj/bubble_drawing.c				\
					src/pnj/check_pnj_talk.c				\
					src/pnj/draw_pnj.c						\
					src/pnj/move_pnj.c						\
					src/pnj/quest_advencement.c				\
					src/pnj/pnj_text.c						\
					src/pnj/text_with_sword.c				\
					src/pnj/which_pnj_has_quest.c			\

SRC_MENU		= 	src/menu/menu.c							\
					src/menu/menu_create.c					\
					src/menu/menu_animation.c				\
					src/menu/menu_settings.c				\
					src/menu/menu_htp.c						\
					src/menu/menu_draw.c 					\
					src/menu/move_elements.c				\

SRC_BUTTON		=	src/menu/buttons/menu_button.c			\
					src/menu/buttons/button_create.c		\
					src/menu/buttons/menu_button_case.c

SRC_MAP			=	src/map/map_create.c					\
					src/map/check_change_map.c				\

SRC_UTILS	    =	src/utils/error.c						\
					src/utils/my_malloc.c					\
					src/utils/ratio_window.c				\
					src/utils/my_itoa.c						\
					src/utils/my_put_str.c

SRC_TEST		=	units_tests/test.c

OBJ 			=	$(SRC_MAIN:.c=.o)						\
					$(SRC_GAME:.c=.o)						\
					$(SRC_MENU:.c=.o)						\
					$(SRC_PLAYER:.c=.o)						\
					$(SRC_MAP:.c=.o)						\
					$(SRC_BUTTON:.c=.o)						\
					$(SRC_UTILS:.c=.o)

OBJ_TEST		=	$(SRC_UTILS:.c=.o)						\
					$(SRC_GAME:.c=.o)						\
					$(SRC_MENU:.c=.o)						\
					$(SRC_PLAYER:.c=.o)						\
					$(SRC_MAP:.c=.o)						\
					$(SRC_BUTTON:.c=.o)						\
					$(SRC_TEST:.c=.o)

CFLAGS			=	-W -Wall -Wextra -I./include -L./lib

CSFMLFLAGS 		=  -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIBFLAGS		=	-lmy

FLAGS_DEBUG 	= 	-g3

FLAGS_TEST 		=	--coverage -lcriterion

NAME			=	my_rpg

NAME_TEST		= 	unit_tests

$(NAME):			$(OBJ)

					make -C lib/my
					gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(CFLAGS) $(LIBFLAGS)

all:				message $(NAME)

message:
			$(ECHO) " ___  ___ _____ _____    _____                 _       "
			$(ECHO) " |  \/  |/  ___/  __ \  |  _  |               | |      "
			$(ECHO) " | .  . |\ °--.| /  \/  | | | |_   _  ___  ___| |_     "
			$(ECHO) " | |\/| | °--. \ |      | | | | | | |/ _ \/ __| __|    "
			$(ECHO) " | |  | |/\__/ / \__/\  \ \/' / |_| |  __/\__ \ |_     "
			$(ECHO) " \_|  |_/\____/ \____/   \_/\_\\\__,_|\___||___/\__|   "
			$(ECHO) ""

debug: 				CFLAGS += $(FLAGS_DEBUG)

debug:				$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(CFLAGS)

clean:
					rm -rf $(OBJ)

clean_test:
					rm -rf $(OBJ_TEST)
					find . -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean:
					find . -name "*.gcda" -delete -or -name "*.gcno" -delete
					find . -name "*.a" -delete -or -name "*.o" -delete
					find . -name "vgcore.*" -delete
					rm -rf $(NAME_TEST)
					rm -rf $(NAME)

tests_run:			CFLAGS += --coverage

tests_run: 			$(OBJ_TEST)
					gcc -o $(NAME_TEST) $(OBJ_TEST) $(CFLAGS) $(FLAGS_TEST)
					./unit_tests --verbose

re:					fclean all

.PHONY: 			all message debug clean clean_test fclean tests_run re
