/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** game_scene
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../../../include/my_hunter.h"
#include "../../../include/structure.h"
#include "../../../include/entity.h"
#include "../../../include/my_list.h"
#include "../../../include/event.h"
#include "../../../include/utils.h"
#include "../../../include/engine.h"
#include "../../../include/scenes.h"

void render_game_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (((entity_t *)temp->data)->state == ACTIVE)
            sfRenderWindow_drawSprite(engine->window,
                ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

void update_pause_game(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    engine->music_selector = PAUSE;
    switch_pause_music(engine);
    while (temp != NULL) {
        if (((entity_t *)(temp->data))->id == 2) {
            manage_pause_game(engine, temp->data);
        }
        temp = temp->next;
    }
}

static void animate_chicken(entity_t *entity)
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

static void set_chicken_vector(entity_t *entity)
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

static void move_chicken(entity_t *entity)
{
    sfVector2f new_pos = {10 * cos(entity->direction_angle),
        10 * sin(entity->direction_angle)};

    sfSprite_move(entity->sprite, new_pos);
}

static void update_chicken(entity_t *entity, scene_t *scene, engine_t *engine)
{
    animate_chicken(entity);
    set_chicken_vector(entity);
    move_chicken(entity);
    manage_chicken_click(entity, engine);
}

static void create_chicken_each_frame(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp;
    entity_t *duck;

    if (sfTime_asSeconds(sfClock_getElapsedTime(scene->clock)) > 0.2) {
        duck = create_entity(GET_RES(chicken),
            get_random_pos(engine), 84, update_chicken);
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

int update_game_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    switch_game_music(engine);
    create_chicken_each_frame(scene, engine);
    while (temp != NULL) {
        if (((entity_t *)(temp->data))->id == 2)
            manage_pause_game(engine, temp->data);
        if (((entity_t *)(temp->data))->id == 3) {
            set_sprite_hover(((entity_t *)(temp->data))->sprite, engine,
            engine->ressources->quit_button_hover,
            engine->ressources->quit_button);
        }
        if (MOUSE_PRESSED() && IS_ENTITY(3) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite))
                engine->current_scene = get_scene_by_id(engine, 1);
        temp = temp->next;
    }
    return 1;
}

static void destroy_game_scene(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    sfClock_destroy(scene->clock);
    free(scene);
}

scene_t *init_game_scene(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *game_scene = malloc(sizeof(scene_t));

    srand(time(NULL));
    sfMusic_setLoop(GET_RES(game_music), sfTrue);
    entity_list = push_front_list_all(entity_list, 3,
        create_entity(GET_RES(quit_button), POS(30, 30), 3, NULL),
        create_entity(GET_RES(pause_button), POS(1739, 30), 2, NULL),
        create_entity(GET_RES(game_background), POS(0, 0), 1, NULL));
    game_scene->id = 3;
    game_scene->clock = sfClock_create();
    game_scene->entity_list = entity_list;
    game_scene->scene_render = &render_game_scene;
    game_scene->scene_update = &update_game_scene;
    game_scene->scene_pause_update = &update_pause_game;
    game_scene->scene_destroy = &destroy_game_scene;
    return game_scene;
}
