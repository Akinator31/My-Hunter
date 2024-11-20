/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** start_page
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../../../include/my_hunter.h"
#include "../../../include/structure.h"
#include "../../../include/entity.h"
#include "../../../include/my_list.h"

void render_main_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window, ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

void destroy_main_page(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp->next != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
    }
}

scene_t *init_main_page(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *main_scene = malloc(sizeof(scene_t));
    entity_t *background = create_entity(engine->ressources->background, POS(0, 0), AREA(1920, 1080));
    entity_t *play_button = create_entity(engine->ressources->play_button, POS(150, 800), AREA(700, 352));
    entity_t *quit_button = create_entity(engine->ressources->quit_button, POS(300, 800), AREA(360, 353));

    entity_list = push_front_list(entity_list, play_button);
    entity_list = push_front_list(entity_list, quit_button);
    entity_list = push_front_list(entity_list, background);
    main_scene->id = 1;
    main_scene->entity_list = entity_list;
    main_scene->scene_render = &render_main_page;
    main_scene->scene_destroy = &destroy_main_page;
    engine->current_scene = main_scene;
    return main_scene;
}