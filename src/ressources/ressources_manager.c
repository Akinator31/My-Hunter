/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** ressources_manager
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../../include/my_hunter.h"
#include "../../include/structure.h"

static const char *assets[] = {
    "assets/images/main_menu/bg.png",
    "assets/images/main_menu/buttons/start_button.png",
    "assets/images/main_menu/buttons/hover/start_button_hover.png",
    "assets/images/main_menu/buttons/quit_button.png",
    "assets/images/main_menu/buttons/hover/quit_button_hover.png",
    "assets/images/main_menu/buttons/settings_button.png",
    "assets/images/main_menu/buttons/hover/settings_button_hover.png",
    "assets/images/settings_menu/buttons/sound_on.png",
    "assets/images/settings_menu/buttons/hover/sound_on_hover.png",
    "assets/images/settings_menu/buttons/sound_off.png",
    "assets/images/settings_menu/buttons/hover/sound_off_hover.png",
    "assets/images/settings_menu/buttons/back_button.png",
    "assets/images/settings_menu/buttons/hover/back_button_hover.png",
    "assets/images/settings_menu/settings_bg.png",
    "assets/images/settings_menu/buttons/900.png",
    "assets/images/settings_menu/buttons/1920.png",
    "assets/images/settings_menu/buttons/4k.png",
    "assets/images/settings_menu/buttons/hover/900_hover.png",
    "assets/images/settings_menu/buttons/hover/1920_hover.png",
    "assets/images/settings_menu/buttons/hover/4k_hover.png",
    "assets/sounds/menu-music.ogg",
    "assets/sounds/game-music.ogg",
};

void destroy_secondary_ressources(ressource_manager_t *ressources)
{
    sfTexture_destroy(ressources->res_900);
    sfTexture_destroy(ressources->res_1920);
    sfTexture_destroy(ressources->res_4k);
    sfTexture_destroy(ressources->res_900_hover);
    sfTexture_destroy(ressources->res_1920_hover);
    sfTexture_destroy(ressources->res_4k_hover);
}

void destroy_ressources(ressource_manager_t *ressources)
{
    sfTexture_destroy(ressources->background);
    sfTexture_destroy(ressources->play_button);
    sfTexture_destroy(ressources->play_button_hover);
    sfTexture_destroy(ressources->quit_button);
    sfTexture_destroy(ressources->quit_button_hover);
    sfTexture_destroy(ressources->settings_button);
    sfTexture_destroy(ressources->settings_button_hover);
    sfTexture_destroy(ressources->sound_on_button);
    sfTexture_destroy(ressources->sound_off_button);
    sfTexture_destroy(ressources->sound_on_button_hover);
    sfTexture_destroy(ressources->sound_off_button_hover);
    sfTexture_destroy(ressources->back_button);
    sfTexture_destroy(ressources->back_button_hover);
    sfTexture_destroy(ressources->settings_background);
    sfMusic_destroy(ressources->menu_music);
    sfMusic_destroy(ressources->game_music);
    destroy_secondary_ressources(ressources);
}

void create_secondary_ressources(ressource_manager_t *ressources)
{
    SFTX(ressources->res_900, 14);
    SFTX(ressources->res_1920, 15);
    SFTX(ressources->res_4k, 16);
    SFTX(ressources->res_900_hover, 17);
    SFTX(ressources->res_1920_hover, 18);
    SFTX(ressources->res_4k_hover, 19);
    SFMS(ressources->menu_music, 20);
    SFMS(ressources->game_music, 21);
}

ressource_manager_t *create_ressources(void)
{
    ressource_manager_t *ressources = malloc(sizeof(ressource_manager_t));

    SFTX(ressources->background, 0);
    SFTX(ressources->play_button, 1);
    SFTX(ressources->play_button_hover, 2);
    SFTX(ressources->quit_button, 3);
    SFTX(ressources->quit_button_hover, 4);
    SFTX(ressources->settings_button, 5);
    SFTX(ressources->settings_button_hover, 6);
    SFTX(ressources->sound_on_button, 7);
    SFTX(ressources->sound_on_button_hover, 8);
    SFTX(ressources->sound_off_button, 9);
    SFTX(ressources->sound_off_button_hover, 10);
    SFTX(ressources->back_button, 11);
    SFTX(ressources->back_button_hover, 12);
    SFTX(ressources->settings_background, 13);
    create_secondary_ressources(ressources);
    ressources->destroy_ressources = &destroy_ressources;
    return ressources;
}
