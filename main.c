#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

sfRenderWindow *create_window(unsigned int width, unsigned int heigth, char *window_title)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = heigth;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, window_title, sfDefaultStyle, NULL);

    return window;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int heigth)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));
    fb->pixels = malloc(width * heigth * 32 / 8),
    fb->width = width;
    fb->height = heigth;
    return fb;
}

void my_put_pixel()
{

}

void framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixels);
    free(fb);
}

void framebuffer_drawsquare(framebuffer_t *fb, int size, sfVector2i pos, sfColor *color)
{
    for (int i = 0; i <= size; i++) { // each line
        for (int e = 0; e <= size * 4; e++) { // each pixel on the line
            fb->pixels[fb->width * pos.y + pos.x + (fb->width * 4 * i) + e] = color->r;
            fb->pixels[fb->width * pos.y + pos.x + (fb->width * 4 * i) + e + 1] = color->g;
            fb->pixels[fb->width * pos.y + pos.x + (fb->width * 4 * i) + e + 2] = color->b;
            fb->pixels[fb->width * pos.y + pos.x + (fb->width * 4 * i) + e + 3] = color->a;
            e += 3;
        }
    }
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
    int width = 800;
    int heigth = 600;
    sfVector2i pos = {200, 300};
    sfRenderWindow *window;
    framebuffer_t *fb;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfIntRect rect;
    sfTexture *texture2 = sfTexture_createFromFile("B-MUL-100_Bootstrap_my_hunter_spritesheet.png", NULL);
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    window = create_window(width, heigth, "window");
    fb = framebuffer_create(width, heigth);
    texture = sfTexture_create(width, heigth);
    sprite = sfSprite_create();

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    sfSprite_setTexture(sprite, texture2, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTextureRect(sprite, rect);
        analyse_events(window, event);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            move_rect(&rect, 110, 330);
            sfClock_restart(clock);
        }
        //framebuffer_drawsquare(fb, 200, pos, &sfYellow);
        //sfTexture_updateFromPixels(texture, fb->pixels, 800, 600, 0, 0);
        //sfSprite_setTexture(sprite, texture, sfFalse);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    framebuffer_destroy(fb);
    sfTexture_destroy(texture);
    sfTexture_destroy(texture2);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(window);
}