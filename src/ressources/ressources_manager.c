/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** ressources_manager
*/

#include <SFML/Graphics.h>
#include "../../include/my_hunter.h"
#include "../../include/structure.h"

ressource_manager_t *create_ressources(void)
{
    sfImage *background = sfImage_createFromFile("assets/images/main_menu/bg1.png");
    sfImage *start_button = sfImage_createFromFile("assets/images/main_menu/buttons/start_button.png");
    sfImage *quit_button = sfImage_createFromFile("assets/images/main_menu/buttons/quit_button.png");
    ressource_manager_t *ressources = {
        background,
        start_button, 
        quit_button
    };
    return ressources;
}