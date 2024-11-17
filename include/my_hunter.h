/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include "structure.h"

typedef struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

struct main_window {
    sfRenderWindow *window;
};

sfRenderWindow *create_window(unsigned int width, unsigned int heigth, char *window_title);
void load_main_page(sfRenderWindow *window);