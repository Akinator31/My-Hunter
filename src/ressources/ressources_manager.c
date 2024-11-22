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
    "assets/sounds/menu-music.ogg",
    "assets/sounds/game-music.ogg",
};

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
    sfMusic_destroy(ressources->menu_music);
    sfMusic_destroy(ressources->game_music);
}

ressource_manager_t *create_ressources(void)
{
    ressource_manager_t *ressources = malloc(sizeof(ressource_manager_t));

    SFTX(background, 0);
    SFTX(play_button, 1);
    SFTX(play_button_hover, 2);
    SFTX(quit_button, 3);
    SFTX(quit_button_hover, 4);
    SFTX(settings_button, 5);
    SFTX(settings_button_hover, 6);
    SFTX(sound_on_button, 7);
    SFTX(sound_off_button, 8);
    SFTX(sound_on_button_hover, 9);
    SFTX(sound_off_button_hover, 10);
    SFTX(back_button, 11);
    SFTX(back_button_hover, 12);
    SFMS(menu_music, 13);
    SFMS(game_music, 14);
    ressources->destroy_ressources = &destroy_ressources;
    return ressources;
}
