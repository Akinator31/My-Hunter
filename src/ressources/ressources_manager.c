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

void destroy_ressources(ressource_manager_t *ressources)
{
    sfTexture_destroy(ressources->background);
    sfTexture_destroy(ressources->play_button);
    sfTexture_destroy(ressources->play_button_hover);
    sfTexture_destroy(ressources->quit_button);
    sfTexture_destroy(ressources->quit_button_hover);
    sfTexture_destroy(ressources->settings_button);
    sfTexture_destroy(ressources->settings_button_hover);
}

ressource_manager_t *create_ressources(void)
{
    ressource_manager_t *ressources = malloc(sizeof(ressource_manager_t));

    ressources->background = sfTexture_createFromFile("assets/images/main_menu/bg.png", &AREA(1920, 1080));
    ressources->play_button = sfTexture_createFromFile("assets/images/main_menu/buttons/start_button.png", &AREA(300, 151));
    ressources->play_button_hover = sfTexture_createFromFile("assets/images/main_menu/buttons/hover/start_button_hover.png", &AREA(300, 151));
    ressources->quit_button = sfTexture_createFromFile("assets/images/main_menu/buttons/quit_button.png", &AREA(154, 151));
    ressources->quit_button_hover = sfTexture_createFromFile("assets/images/main_menu/buttons/hover/quit_button_hover.png", &AREA(161, 151));
    ressources->settings_button = sfTexture_createFromFile("assets/images/main_menu/buttons/settings_button.png", &AREA(154, 151));
    ressources->settings_button_hover = sfTexture_createFromFile("assets/images/main_menu/buttons/hover/settings_button_hover.png", &AREA(154, 151));
    ressources->destroy_ressources = &destroy_ressources;
    return ressources;
}