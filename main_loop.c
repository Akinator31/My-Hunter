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

int main(void)
{
    engine_t *engine = load_game(NAME, WIDTH, HEIGTH, 60);

    while (sfRenderWindow_isOpen(engine->window)) {
        sfRenderWindow_clear(engine->window, sfBlack);
        load_current_scene(engine);
        if (((scene_t *)(engine->current_scene))->scene_update
            (engine->current_scene, engine) == 84)
            return engine_destroy(engine);
        while (sfRenderWindow_pollEvent(engine->window, &engine->event))
            analyse_event(engine->window, &engine->event);
        sfRenderWindow_display(engine->window);
    }
    return engine_destroy(engine);
}
