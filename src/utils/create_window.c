/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** create_window
*/

#include "../../include/my_hunter.h"

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