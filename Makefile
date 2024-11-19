##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =	main_loop.c \
		src/engine/engine.c \
		src/ressources/ressources_manager.c \
		src/event/event_manager.c \

UTILS =	src/utils/create_window.c \
		lib/my_list/add_data.c \
		lib/my_list/info_list.c \
		lib/my_list/remove_data.c \

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

LIB = lib/my_lib/libmy.a

NAME = my_hunter

all: $(NAME)

CFLAGS += -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-network
$(NAME): $(OBJ)
		make -C lib/my_lib
		gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	make clean -C lib/my_lib
	rm -f *.o
	rm -f src/main_page/*.o
	rm -f src/engine/*.o
	rm -f src/entity/*.o
	rm -f src/event/*.o
	rm -f src/ressources/*.o
	rm -f src/scenes/*.o
	rm -f src/utils/*.o
	rm -f lib/my_list/*.o

fclean: clean

re: fclean all