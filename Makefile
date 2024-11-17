##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC =	main.c \
		src/main_page/start_page.c \

UTILS =	src/utils/create_window.c \

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

NAME = my_hunter

all: $(NAME)

CFLAGS += -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-network
$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f *.o
	rm -f src/main_page/*.o
	rm -f src/sprite_manager/*.o
	rm -f src/texture_manager/*.o

fclean: clean

re: fclean all