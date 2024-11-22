##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =	main_loop.c \
		src/engine/engine.c \
		src/engine/load_current_scene.c \
		lib/my_lib/my_list/add_data.c \
		lib/my_lib/my_list/info_list.c \
		lib/my_lib/my_list/remove_data.c \

SCENES =	src/scenes/scenes_manager.c \
			src/scenes/main_menu/main_menu.c \
			src/scenes/settings_menu/settings_menu.c \

ENTITY = 	src/entity/entity.c \

RESSOURCES = 	src/ressources/ressources_manager.c \

EVENT = 	src/event/event_manager.c \

UTILS =	src/utils/create_window.c \
		src/utils/set_sprite_hover.c \
		src/utils/is_mouse_on_sprite.c \
		src/utils/get_scene_by_id.c \

OBJ = 	$(SRC:.c=.o) $(SCENES:.c=.o) $(RESSOURCES:.c=.o) \
		$(EVENT:.c=.o) $(ENTITY:.c=.o) $(UTILS:.c=.o)

LIB = lib/my_lib/libmy.a

NAME = my_hunter

all: $(NAME)

CFLAGS += -lcsfml-audio -lcsfml-graphics -lcsfml-system
CFLAGS += -lcsfml-window -lcsfml-network -fsanitize=address -g3
$(NAME): $(OBJ)
		make -C lib/my_lib
		gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	make clean -C lib/my_lib
	rm -f *.o
	rm -f src/scenes/main_menu/*.o
	rm -f src/scenes/game/*.o
	rm -f src/scenes/pause_menu/*.o
	rm -f src/scenes/settings_menu/*.o
	rm -f src/scenes/*.o
	rm -f src/engine/*.o
	rm -f src/entity/*.o
	rm -f src/event/*.o
	rm -f src/ressources/*.o
	rm -f src/utils/*.o
	rm -f lib/my_list/*.o

fclean: clean

re: fclean all
