/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** event_manager
*/

#include <SFML/Graphics.h>
#include "../../include/my_hunter.h"
#include "../../include/structure.h"
#include "../../include/utils.h"
#include "../../include/event.h"

void manage_music_button_hover(engine_t *engine, entity_t *entity)
{
    if (engine->music_state == PLAYING)
        set_sprite_hover(entity->sprite, engine,
            GET_RES(sound_on_button_hover), GET_RES(sound_on_button));
    else
        set_sprite_hover(entity->sprite, engine,
            GET_RES(sound_off_button_hover), GET_RES(sound_off_button));
}

void manage_pause_button_hover(engine_t *engine, entity_t *entity)
{
    if (engine->state == RUNNING)
        set_sprite_hover(entity->sprite, engine,
            GET_RES(pause_button_hover), GET_RES(pause_button));
    else
        set_sprite_hover(entity->sprite, engine,
            GET_RES(resume_button_hover), GET_RES(resume_button));
}

void manage_music(engine_t *engine, entity_t *entity)
{
    manage_music_button_hover(engine, entity);
    if (engine->event.type != sfEvtMouseButtonPressed)
        return;
    if (!is_mouse_on_sprite(engine, entity->sprite))
        return;
    if (sfTime_asSeconds(sfClock_getElapsedTime(engine->clock)) < 0.2)
        return;
    if (engine->music_state == PLAYING) {
        sfMusic_pause(engine->ressources->menu_music);
        sfClock_restart(engine->clock);
        engine->music_state = STOPPED;
    } else {
        sfMusic_play(engine->ressources->menu_music);
        sfClock_restart(engine->clock);
        engine->music_state = PLAYING;
    }
}

void manage_pause_game(engine_t *engine, entity_t *entity)
{
    manage_pause_button_hover(engine, entity);
    if (engine->event.type != sfEvtMouseButtonPressed)
        return;
    if (!is_mouse_on_sprite(engine, entity->sprite))
        return;
    if (sfTime_asSeconds(sfClock_getElapsedTime(engine->clock)) < 0.2)
        return;
    if (engine->state == RUNNING) {
        engine->state = PAUSED;
        sfClock_restart(engine->clock);
    } else {
        engine->state = RUNNING;
        switch_game_music(engine);
        engine->music_selector = GAME_MUSIC;
        sfClock_restart(engine->clock);
    }
}

void analyse_event(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}
