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
#include <SFML/Graphics/RenderStates.h>
#include "my_hunter.h"
#include "structure.h"
#include "entity.h"
#include "my_list.h"
#include "event.h"
#include "utils.h"
#include "engine.h"
#include "scenes.h"
#include "chicken.h"

void render_game_scene(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (((entity_t *)temp->data)->is_text == 1) {
            sfRenderWindow_drawText(engine->window,
                ((entity_t *)temp->data)->text, NULL);
            temp = temp->next;
            continue;
        }
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
    entity_list = push_front_list_all(entity_list, 4,
        create_entity(GET_RES(quit_button), POS(30, 30), 3, NULL),
        create_entity(GET_RES(pause_button), POS(1739, 30), 2, NULL),
        create_text(0, POS(1200, 40), engine),
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
