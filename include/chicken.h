/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** chicken
*/

#ifndef INCLUDED_CHICKEN_H
    #define INCLUDED_CHICKEN_H
    #include "structure.h"

void animate_chicken(entity_t *entity);
void set_chicken_vector(entity_t *entity);
void move_chicken(entity_t *entity);
void update_chicken(entity_t *entity, scene_t *scene, engine_t *engine);
void create_chicken_each_frame(scene_t *scene, engine_t *engine);

#endif
