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
#include "../../include/utils.h"

engine_t *load_game(char *title, int width, unsigned int height, unsigned int default_framerate)
{
    engine_t *engine = malloc(sizeof(*engine));
    sfRenderWindow *window = create_window(width, height, title);
    sfClock *clock = sfClock_create();
    scene_t *current_scene = NULL;
    linked_list_t *scene_list = new_list(sizeof(scene_t));
    ressource_manager_t *ressources = create_ressources();
    sfEvent event;
    bool is_running = false;
    float delta_time = 0.0;
    engine->window = window;
    engine->clock = clock;
    engine->current_scene = NULL;
    engine->scenes_list = new_list(sizeof(scene_t));
    engine->ressources = ressources;
    engine->event = event;
    engine->is_running = false;
    engine->delta_time = delta_time;
    engine->default_fps_framerate = default_framerate;
    return engine;
}

void engine_destroy(engine_t *engine)
{
    free(engine->window);
    free(engine->clock);
    free(engine->current_scene);
    free(engine->scenes_list);
    free(engine->ressources);
    free(engine);
}