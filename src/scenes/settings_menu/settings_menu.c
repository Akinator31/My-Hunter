/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** settings_page
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../../../include/my_hunter.h"
#include "../../../include/structure.h"
#include "../../../include/entity.h"
#include "../../../include/my_list.h"
#include "../../../include/event.h"
#include "../../../include/utils.h"

void render_settings_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window,
            ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

int update_button_hover_settings(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        if (((entity_t *)(temp->data))->id == 3) {
            set_sprite_hover(GET_SPRITE(), engine,
                GET_RES(back_button_hover), GET_RES(back_button));
        }
        temp = temp->next;
    }
}

int update_settings_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);

    update_button_hover_settings(scene, engine);
    while (temp != NULL) {
        if (MOUSE_RELEASED() && IS_ENTITY(3) &&
            IS_CLICK(((entity_t *)(temp->data))->sprite)) {
            engine->current_scene = get_scene_by_id(engine, 1);
        }
        if (((entity_t *)(temp->data))->id == 2) {
            manage_music(engine, temp->data);
        }
        temp = temp->next;
    }
}

void destroy_settings_page(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
        temp = temp->next;
    }
    clear_list(scene->entity_list);
    free(scene);
}

scene_t *init_settings_page(engine_t *engine)
{
    linked_list_t *entity_list = new_list();
    scene_t *main_scene = malloc(sizeof(scene_t));

    entity_list = push_front_list_all(entity_list, 3,
        create_entity(engine->ressources->sound_on_button, POS(100, 500), 2),
        create_entity(engine->ressources->back_button, POS(1736, 30), 3),
        create_entity(engine->ressources->settings_background, POS(0, 0), 1));
    main_scene->id = 2;
    main_scene->entity_list = entity_list;
    main_scene->scene_render = &render_settings_page;
    main_scene->scene_update = &update_settings_page;
    main_scene->scene_destroy = &destroy_settings_page;
    return main_scene;
}
