/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** start_page
*/

#include <SFML/Graphics.h>
#include "../../include/my_hunter.h"
#include "../../include/structure.h"

void load_button_main_page(sfRenderWindow *window)
{
    sfImage *start_button = sfImage_createFromFile("src/images/main_menu/buttons/start_button.png");
    sfIntRect start_button_area = {700, 352};
    sfTexture *texture = sfTexture_createFromImage(start_button, &start_button_area);
    sfSprite *button_sprite = sfSprite_create();
    sfVector2f start_button_pos = {800, 800};

    sfSprite_setTexture(button_sprite, texture, sfFalse);
    sfSprite_setPosition(button_sprite, start_button_pos);
    sfRenderWindow_drawSprite(window, button_sprite, NULL);
    sfTexture_destroy(texture);
    sfImage_destroy(start_button);
    sfSprite_destroy(button_sprite);
}

void load_main_page(sfRenderWindow *window)
{
    sfImage *background = sfImage_createFromFile("src/images/main_menu/bg.png");
    sfIntRect background_area = {1920, 1080};
    sfTexture *texture = sfTexture_createFromImage(background, &background_area);
    sfSprite *background_sprite = sfSprite_create();
    
    sfSprite_setTexture(background_sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, background_sprite, NULL);
    load_button_main_page(window);
    sfTexture_destroy(texture);
    sfImage_destroy(background);
    sfSprite_destroy(background_sprite);
}