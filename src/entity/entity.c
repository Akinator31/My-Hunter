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
    sfClock_destroy(entity->clock);
    free(entity);
}

entity_t *create_entity(sfTexture *texture, sfVector2f pos, int id,
    void (*entity_update)(entity_t *entity, scene_t *scene, engine_t *engine))
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sfSprite_create();
    entity->pos = pos;
    entity->id = id;
    entity->entity_destroy = &destroy_entity;
    entity->entity_update = entity_update;
    entity->clock = sfClock_create();
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    sfSprite_setTextureRect(entity->sprite,
        sfSprite_getTextureRect(entity->sprite));
    sfSprite_setPosition(entity->sprite, pos);
    return entity;
}
