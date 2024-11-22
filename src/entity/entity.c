/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** entity
*/

#include <stdlib.h>
#include "../../include/structure.h"
#include "../../include/entity.h"

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    free(entity);
}

// entity_t *change_entity_image(entity_t *entity, sfImage *image, sfIntRect area, engine_t *engine)
// {
//     sfTexture_destroy(entity->texture);
//     entity->sprite = 
// }

entity_t *create_entity(sfTexture *texture, sfVector2f pos, int id)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sfSprite_create();
    entity->pos = pos;
    entity->id = id;
    entity->entity_destroy = &destroy_entity;
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    sfSprite_setPosition(entity->sprite, pos);
    return entity;
}
