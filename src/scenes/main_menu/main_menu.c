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
#include "../../../include/event.h"
#include "../../../include/utils.h"

void render_main_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window, ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

void update_main_page(scene_t *scene, engine_t *engine, float delta_time)
{
    linked_list_t *temp = scene->entity_list;
    sfFloatRect texture_rect;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);

    while (temp != NULL) {
        if (((entity_t *)(temp->data))->id == 2) {
            set_sprite_hover(((entity_t *)(temp->data))->sprite, mouse_pos, engine->ressources->play_button_hover, engine->ressources->play_button);
        }
        if (((entity_t *)(temp->data))->id == 3) {
            set_sprite_hover(((entity_t *)(temp->data))->sprite, mouse_pos, engine->ressources->quit_button_hover, engine->ressources->quit_button);
        }
        if (((entity_t *)(temp->data))->id == 4) {
            set_sprite_hover(((entity_t *)(temp->data))->sprite, mouse_pos, engine->ressources->settings_button_hover, engine->ressources->settings_button);
        }
        temp = temp->next;
    }
}

void destroy_main_page(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    free(scene);
}

scene_t *init_main_page(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *main_scene = malloc(sizeof(scene_t));
    entity_t *background = create_entity(engine->ressources->background, POS(0, 0), AREA(1920, 1080), 1);
    entity_t *play_button = create_entity(engine->ressources->play_button, POS(150, 800), AREA(300, 151), 2);
    entity_t *quit_button = create_entity(engine->ressources->quit_button, POS(500, 800), AREA(154, 151), 3);
    entity_t *settings_button = create_entity(engine->ressources->settings_button, POS(1736, 30), AREA(154, 151), 4);

    entity_list = push_front_list(entity_list, play_button);
    entity_list = push_front_list(entity_list, quit_button);
    entity_list = push_front_list(entity_list, settings_button);
    entity_list = push_front_list(entity_list, background);
    main_scene->id = 1;
    main_scene->entity_list = entity_list;
    main_scene->scene_render = &render_main_page;
    main_scene->scene_update = &update_main_page;
    main_scene->scene_destroy = &destroy_main_page;
    engine->current_scene = main_scene;
    return main_scene;
}