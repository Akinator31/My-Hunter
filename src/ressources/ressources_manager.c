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

ressource_manager_t *create_ressources(void)
{
    ressource_manager_t *ressources = malloc(sizeof(ressource_manager_t));
    sfImage *background = sfImage_createFromFile("assets/images/main_menu/bg.png");
    sfImage *play_button = sfImage_createFromFile("assets/images/main_menu/buttons/start_button.png");
    sfImage *quit_button = sfImage_createFromFile("assets/images/main_menu/buttons/quit_button.png");

    ressources->background = background;
    ressources->play_button = play_button;
    ressources->quit_button = quit_button;
    return ressources;
}