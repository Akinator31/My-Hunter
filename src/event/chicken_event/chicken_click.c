/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** chicken_click
*/

#include "../../../include/structure.h"
#include "../../../include/event.h"
#include "../../../include/entity.h"

void manage_chicken_click(entity_t *entity, engine_t *engine)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(entity->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);
    sfVector2f window_size = {sfRenderWindow_getSize(engine->window).x,
        sfRenderWindow_getSize(engine->window).y};

    if ((engine->event.type == sfEvtMouseButtonPressed) &&
        sfFloatRect_contains(&sprite_rect, mouse_pos.x *
            (1080 / window_size.y), mouse_pos.y * (1080 / window_size.y))) {
        entity->state = TOUCH;
    }
}
