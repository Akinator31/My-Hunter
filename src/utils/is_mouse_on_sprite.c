/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** is_mouse_on_sprite
*/

#include "../../include/structure.h"
#include "../../include/engine.h"
#include <stdio.h>

sfBool is_mouse_on_sprite(engine_t *engine, sfSprite *sprite, sfVector2i mouse_pos)
{
    sfFloatRect texture_rect = sfSprite_getGlobalBounds(sprite);
    sfVector2f window_size = {sfRenderWindow_getSize(engine->window).x, sfRenderWindow_getSize(engine->window).y};

    if (sfFloatRect_contains(&texture_rect, mouse_pos.x * (1920 / window_size.x), mouse_pos.y * (1080 / window_size.y)))
        return sfTrue;
    return sfFalse;
}
