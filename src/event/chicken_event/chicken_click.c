/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** chicken_click
*/

#include <stdlib.h>
#include "structure.h"
#include "event.h"
#include "entity.h"
#include "my_lib.h"

static void update_score(scene_t *scene, engine_t *engine, entity_t *entity)
{
    linked_list_t *temp = scene->entity_list;
    char *score = my_strnum(engine->score);

    while (temp != NULL) {
        if ((((entity_t *)(temp->data))->is_text == 1) &&
            (entity->state == ACTIVE)) {
            engine->score += 1;
            sfText_setString(((entity_t *)(temp->data))->text,
                score);
        }
        temp = temp->next;
    }
    free(score);
}

void manage_chicken_click(entity_t *entity, engine_t *engine, scene_t *scene)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(entity->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);
    sfVector2f window_size = {sfRenderWindow_getSize(engine->window).x,
        sfRenderWindow_getSize(engine->window).y};

    if ((engine->event.type == sfEvtMouseButtonPressed) &&
        sfFloatRect_contains(&sprite_rect, mouse_pos.x *
            (1080 / window_size.y), mouse_pos.y * (1080 / window_size.y))) {
        update_score(scene, engine, entity);
        entity->state = TOUCH;
    }
}
