/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** chicken
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "entity.h"
#include "utils.h"
#include "structure.h"
#include "event.h"

void animate_chicken(entity_t *entity)
{
    sfIntRect rect = sfSprite_getTextureRect(entity->sprite);

    rect.height = 260;
    rect.width = 300;
    if (sfTime_asSeconds(sfClock_getElapsedTime(entity->clock)) > 0.2) {
        if (rect.left < 600)
            rect.left += 300;
        else {
            rect.left = 0;
        }
        sfClock_restart(entity->clock);
    }
    sfSprite_setTextureRect(entity->sprite, rect);
}

void set_chicken_vector(entity_t *entity)
{
    sfVector2f entity_pos = sfSprite_getPosition(entity->sprite);

    if (entity->direction_angle == 0) {
        if ((entity_pos.x < 0) && (entity_pos.y < 0)) {
            entity->direction_angle = rand() % 90;
            return;
        }
        if ((entity_pos.x > 0) && (entity_pos.y < 0)) {
            entity->direction_angle = rand() % 180;
            return;
        }
        if ((entity_pos.x > 0) && (entity_pos.y > 0)) {
            entity->direction_angle = rand() % 180;
            return;
        }
    }
}

void move_chicken(entity_t *entity)
{
    sfVector2f new_pos = {entity->velocity * cos(entity->direction_angle),
        entity->velocity * sin(entity->direction_angle)};

    sfSprite_move(entity->sprite, new_pos);
}

void update_chicken(entity_t *entity, scene_t *scene, engine_t *engine)
{
    if (scene->id) {
        animate_chicken(entity);
        set_chicken_vector(entity);
        move_chicken(entity);
        manage_chicken_click(entity, engine, scene);
    }
}

void create_chicken_each_frame(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp;
    entity_t *duck;

    if (sfTime_asSeconds(sfClock_getElapsedTime(scene->clock)) > 0.2) {
        duck = create_entity(GET_RES(chicken),
            get_random_pos(engine), 84, update_chicken);
        duck->velocity = (rand() % 30) + 1;
        duck->direction_angle = 0;
        scene->entity_list = push_back_list(scene->entity_list, duck);
        sfClock_restart(scene->clock);
    }
    temp = scene->entity_list;
    while (temp != NULL) {
        if (((entity_t *)(temp->data))->id == 84) {
            ((entity_t *)(temp->data))->
                entity_update(temp->data, scene, engine);
        }
        temp = temp->next;
    }
}
