#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/my_hunter.h"
#define WIDTH 1920
#define HEIGTH 1080

sfRenderWindow *create_window(unsigned int width, unsigned int heigth, char *window_title)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = heigth;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, window_title, sfResize | sfClose, NULL);
    return window;
}

void manage_mouse_click(sfMouseButtonEvent event)
{
    printf("Mouse x=%d y=%d\n", event.x, event.y);
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            manage_mouse_click(event.mouseButton);
        }
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

int main(void)
{
    sfRenderWindow *window = create_window(WIDTH, HEIGTH, "window");
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    sfIntRect rect;
    sfTexture *texture = sfTexture_createFromFile("src/images/chicken_sprite.png", NULL);
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    rect.top = 0;
    rect.left = 0;
    rect.width = 200;
    rect.height = 180;
    sfSprite_setTexture(sprite, texture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTextureRect(sprite, rect);
        analyse_events(window, event);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            move_rect(&rect, 200, 600);
            sfClock_restart(clock);
        }
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(window);
}