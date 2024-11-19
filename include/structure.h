/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** structure
*/

#ifndef INCLUDED_STRUCTURE_H
    #define INCLUDED_STRUCTURE_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "my_list.h"

typedef struct engine_s engine_t;
typedef struct scene_s scene_t;
typedef struct entity_s entity_t;
typedef struct ressource_manager_s ressource_manager_t;

enum entity_state {
    ACTIVE,
    TOUCH,
    OFF_SCREEN
};

enum game_state {
    RUNNING,
    PAUSED,
    STOPED
};

struct engine_s {
    sfRenderWindow *window;
    sfClock *clock;
    scene_t *current_scene;
    linked_list_t *scenes_list;
    ressource_manager_t *ressources;
    sfEvent event;
    bool is_running;
    float delta_time;
    int default_fps_framerate;
};

struct scene_s {
    int id;
    linked_list_t *entity_list;
    void (*scene_init)(scene_t *scene, engine_t *engine);
    void (*scene_update)(scene_t *scene, engine_t *engine, float delta_time);
    void (*scene_render)(scene_t *scene, engine_t *engine);
    scene_t *(*scene_transition)(scene_t *current_scene, engine_t engine);
    void (*scene_destroy)(scene_t *scene);
};

struct entity_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f *pos;
    int velocity;
    int state;
    void (*entity_init)(entity_t *entity, scene_t *scene, engine_t *engine);
    void (*entity_update)(entity_t *entity, scene_t *scene, engine_t *engine, float delta_time);
    void (*entity_render)(entity_t *entity, engine_t *engine);
    sfBool (*entity_check_collision)(entity_t *entity, entity_t *other);
    void (*entity_destroy)(entity_t *entity);
};

struct ressource_manager_s {
    sfImage *background;
    sfImage *play_button;
    sfImage *quit_button;
};

#endif