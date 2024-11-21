/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include <SFML/Graphics.h>

sfRenderWindow *create_window(unsigned int width, unsigned int heigth, char *window_title);
void set_sprite_hover(sfSprite *sprite, sfVector2i mouse_pos, sfTexture *new_texture, sfTexture *original_texture);

#endif