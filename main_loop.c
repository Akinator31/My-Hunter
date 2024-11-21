/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/my_hunter.h"
#include "include/structure.h"
#include "include/engine.h"
#include "include/scenes.h"
#include "include/event.h"
#define WIDTH 1920
#define HEIGTH 1080
#define NAME "KFC HUNTER"

int main(void)
{
    engine_t *engine = load_game(NAME, WIDTH, HEIGTH, 60);

    sfRenderWindow_setFramerateLimit(engine->window, engine->default_fps_framerate);
    while (sfRenderWindow_isOpen(engine->window)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        printf("FPS : %f\n", 1 / sfTime_asSeconds(sfClock_restart(engine->clock)));
        load_current_scene(engine);
        ((scene_t *)(engine->current_scene))->scene_update(engine->current_scene, engine, engine->delta_time);
        while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
            analyse_event(engine->window, &engine->event);
        }
        sfRenderWindow_display(engine->window);
    }
    engine_destroy(engine);
}