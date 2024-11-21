/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** set_sprite_hover
*/

#include "../../include/structure.h"
#include "../../include/engine.h"

void set_sprite_hover(sfSprite *sprite, sfVector2i mouse_pos, sfTexture *new_texture, sfTexture *original_texture)
{
    sfFloatRect texture_rect = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&texture_rect, mouse_pos.x, mouse_pos.y)) {
        sfSprite_setTexture(sprite, new_texture, sfTrue);
    } else {
        sfSprite_setTexture(sprite, original_texture, sfTrue);
    }
}
