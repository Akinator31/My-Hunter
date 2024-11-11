#include <SFML/Graphics.h>

typedef struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;