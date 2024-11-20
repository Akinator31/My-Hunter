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
#include "../../../include/my_list.h"

void init_main_page(scene_t *scene, engine_t *engine)
{
    linked_list_t *temp = scene->entity_list;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(engine->window, ((entity_t *)temp->data)->sprite, NULL);
        temp = temp->next;
    }
}

void render_main_page(scene_t *scene, engine_t *engine)
{
    sfRenderWindow_clear(engine->window, sfBlack);
    sfRenderWindow_display(engine->window);
}

void destroy_main_page(scene_t *scene)
{
    linked_list_t *temp = scene->entity_list;

    for (int i = 0; temp->next != NULL; i++) {
        ((entity_t *)temp->data)->entity_destroy(temp->data);
    }
}

scene_t *load_main_page(engine_t *engine)
{
    scene_t *main_scene = malloc(sizeof(scene_t));
    linked_list_t *entity_list = new_list();
    entity_t *background = malloc(sizeof(entity_t));
    entity_t *button = malloc(sizeof(entity_t));
    sfVector2f start_button_pos = {800, 800};
    sfVector2f background_pos = {0, 0};
    sfIntRect background_area = {1920, 1080};
    sfIntRect start_button_area = {700, 352};
    sfSprite *background_sprite = sfSprite_create();
    sfSprite *button_sprite = sfSprite_create();
    sfTexture *background_texture = sfTexture_createFromImage(engine->ressources->background, &background_area);
    sfTexture *button_texture = sfTexture_createFromImage(engine->ressources->background, &background_area);

    background->sprite = background_sprite;
    background->texture = background_texture;
    background->pos = NULL;
    button->sprite = button_sprite;
    button->texture = button_texture;
    button->pos = NULL;

    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    entity_list = push_front_list(entity_list, background);
    entity_list = push_front_list(entity_list, button);
    main_scene->id = 1;
    main_scene->entity_list = entity_list;
    main_scene->scene_init = &init_main_page;
    main_scene->scene_render = &render_main_page;
    main_scene->scene_destroy = &destroy_main_page;
    return main_scene;
}