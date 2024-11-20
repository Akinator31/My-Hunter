/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** entity
*/

#include <stdlib.h>
#include "../../include/structure.h"

entity_t *create_entity(sfImage *image, sfVector2f pos, sfIntRect area)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromImage(image, &area);
    entity->pos = pos;
    sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);
    sfSprite_setPosition(entity->sprite, pos);
    return entity;
}