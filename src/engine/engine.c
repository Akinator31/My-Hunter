/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** engine
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../lib/my_lib/my.h"
#include "../../include/my_hunter.h"
#include "../../include/structure.h"
#include "../../include/ressources.h"
#include "../../include/scenes.h"
#include "../../include/utils.h"

engine_t *load_game(char *title, int width,
    unsigned int height, unsigned int default_framerate)
{
    engine_t *engine = malloc(sizeof(*engine));
    sfEvent event;

    engine->window = create_window(width, height, title);
    engine->clock = sfClock_create();
    engine->current_scene = NULL;
    engine->scenes_list = NULL;
    engine->ressources = create_ressources();
    engine->scenes_list = load_scenes(engine);
    engine->event = event;
    engine->is_running = false;
    engine->delta_time = 0.0;
    engine->default_fps_framerate = default_framerate;
    return engine;
}

void clean_scene(linked_list_t *list)
{
    linked_list_t *temp = list;

    while (list != NULL) {
        ((scene_t *)list->data)->scene_destroy(list->data);
        list = list->next;
    }
    clear_list(temp);
}

void engine_destroy(engine_t *engine)
{
    clean_scene(engine->scenes_list);
    sfRenderWindow_destroy(engine->window);
    sfClock_destroy(engine->clock);
    ((ressource_manager_t *)(engine->ressources))->
        destroy_ressources(engine->ressources);
    free(engine->ressources);
    free(engine);
}
