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
			src/scenes/game/chicken.c \

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

LIB = 	lib/my_lib/my_put_nbr.c \
		lib/my_lib/my_strcmp.c \
		lib/my_lib/my_strlowcase.c \
		lib/my_lib/my_strnum.c \
		lib/my_lib/my_putchar.c \
		lib/my_lib/my_strlen.c \

OBJ = 	$(SRC:.c=.o) $(SCENES:.c=.o) $(RESSOURCES:.c=.o) \
		$(EVENT:.c=.o) $(ENTITY:.c=.o) $(UTILS:.c=.o) \
		$(LIB:.c=.o)

NAME = my_hunter

all: $(NAME)

CFLAGS += -lcsfml-audio -lcsfml-graphics -lcsfml-system
CFLAGS += -lcsfml-window -lcsfml-network
CFLAGS += -Wextra -Wall -lm -Iinclude
$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	find . -type f -name "*.o" -delete

fclean: clean

re: fclean all
