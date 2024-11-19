##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## task01
##

SRC = *.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean

re: fclean all
