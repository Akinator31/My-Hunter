#include <SFML/Graphics.h>

typedef struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

struct main_window {
    sfRenderWindow *window;
};

sfRenderWindow *create_window(unsigned int width, unsigned int heigth, char *window_title);