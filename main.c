#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/my_hunter.h"
#define WIDTH 1920
#define HEIGTH 1080
#define NAME "KFC HUNTER"

int main(void)
{
    sfRenderWindow *window = create_window(WIDTH, HEIGTH, "KFC HUNTER");
    sfEvent event;
    sfImage *icon = sfImage_createFromFile("src/images/icon.png");

    sfRenderWindow_setIcon(window, sfImage_getSize(icon).x, sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}