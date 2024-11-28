##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =	main_loop.c \
		src/engine/engine.c \
		src/engine/load_current_scene.c \
		lib/my_list/add_data.c \
		lib/my_list/info_list.c \
		lib/my_list/remove_data.c \

SCENES =	src/scenes/scenes_manager.c \
			src/scenes/main_menu/main_menu.c \
			src/scenes/settings_menu/settings_menu.c \
			src/scenes/game/game_scene.c \

ENTITY = 	src/entity/entity.c \

RESSOURCES = 	src/ressources/ressources_manager.c \

EVENT = 	src/event/event_manager.c \
			src/event/chicken_event/chicken_click.c \

UTILS =	src/utils/create_window.c \
		src/utils/set_sprite_hover.c \
		src/utils/is_mouse_on_sprite.c \
		src/utils/get_scene_by_id.c \
		src/utils/mute_or_unmute_music.c \
		src/utils/switch_music.c \
		src/utils/help_display.c \
		src/utils/get_random_pos.c \

OBJ = 	$(SRC:.c=.o) $(SCENES:.c=.o) $(RESSOURCES:.c=.o) \
		$(EVENT:.c=.o) $(ENTITY:.c=.o) $(UTILS:.c=.o)

LIB = lib/my_lib/libmy.a

NAME = my_hunter

all: $(NAME)

CFLAGS += -lcsfml-audio -lcsfml-graphics -lcsfml-system
CFLAGS += -lcsfml-window -lcsfml-network -fsanitize=address -g3
CFLAGS += -Wextra -Wall -lm
$(NAME): $(OBJ)
		make -C lib/my_lib
		gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	find . -type f -name "*.o" -delete
	make clean -C lib/my_lib

fclean: clean

re: fclean all
